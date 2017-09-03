#include "render_util.h"

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

#define RU_CLEAR_R 0.5f
#define RU_CLEAR_G 0.5f
#define RU_CLEAR_B 0.5f
#define RU_CLEAR_A 0.0f

RenderUtil::RenderUtil()
{
    //ctor
}

RenderUtil::RenderUtil(const RenderUtil& other)
{
    //copy ctor
}

void RenderUtil::clearScreen() {
    // TODO: stencil buffer
    glClearColor(RU_CLEAR_R, RU_CLEAR_G, RU_CLEAR_B, RU_CLEAR_A);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::initGraphics() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // laptop uses 3.0 by default, tell it to use a higher core profile (3.3 at least)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);

    // TODO: Depth Clamp for later

    glEnable(GL_FRAMEBUFFER_SRGB);

}

std::string RenderUtil::getOpenGLVersion() {
    static std::string version((char *)glGetString(GL_VERSION));
    return version;
}

void RenderUtil::shutdown() {
    SDL_Quit();
}

RenderUtil::~RenderUtil()
{
    //dtor
}

