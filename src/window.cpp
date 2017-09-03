#include "window.h"

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "render_util.h"

namespace ogle {
Window::Window(const int width, const int height, const std::string& title)
{
    m_isClosed = false;
    RenderUtil::initGraphics();

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);

    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cerr << "WARNING WILL ROBINSON!" << std::endl;
        std::cerr << "GLEW failed to initialize" << std::endl;
        std::cerr << "GLEW Error Code: " << status << std::endl;
        std::cerr << "GLEW Error Message: " << glewGetErrorString(status);
        exit(1);
    }
}

Window::Window(const Window& other) {
    Window(other.m_width, other.m_height, other.m_title);
}

int Window::getWidth() {
    return m_width;
}

int Window::getHeight() {
    return m_height;
}

void Window::Render() {
    SDL_GL_SwapWindow(m_window);
    SDL_Event e;

    std::vector<SDL_Event> requeueEvents = { };
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_isClosed = true;
        } else {
            requeueEvents.push_back(e);
        }
    }
    for (SDL_Event event : requeueEvents) {
        SDL_PushEvent(&event);
    }
}

bool Window::isClosed() {
    return m_isClosed;
}

Window::~Window()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    RenderUtil::shutdown();
}
}
