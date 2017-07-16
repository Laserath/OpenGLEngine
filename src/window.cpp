#include "window.h"

#include <GL/glew.h>
#include <iostream>
#include <vector>

namespace ogle {
Window::Window(const int width, const int height, const std::string& title)
{
    m_isClosed = false;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);

    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cerr << "WARNING WILL ROBINSON!" << std::endl;
        std::cerr << "GLEW failed to initialize" << std::endl;
    }

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
}

Window::Window(const Window& other) {
    Window(other.m_width, other.m_height, other.m_title);
}

void Window::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    SDL_Quit();
}
}
