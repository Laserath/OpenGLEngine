#include "game.h"

#include "engine_input.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "resource_loader.h"
#include <string>

namespace ogle {

Game::Game()
{
    std::vector<Vertex> vertices = {};

    Vector3f vec3f_bl(-1.0f, -1.0f, 1.0f);
    Vector3f vec3f_br( 1.0f, -1.0f, 1.0f);
    Vector3f vec3f_tm( 0.0f,  1.0f, 1.0f);
    vertices.push_back(Vertex(vec3f_bl));
    vertices.push_back(Vertex(vec3f_tm));
    vertices.push_back(Vertex(vec3f_br));

    m_mesh.addVertices(vertices);

    std::string vertexShader = *ResourceLoader::loadShader("shaders/basicVertex.vs");
    std::string fragmentShader = *ResourceLoader::loadShader("shaders/basicFragment.fs");

    //std::cout << "=== vertexShader ===" << std::endl;
    //std::cout << vertexShader << std::endl;

    //std::cout << "=== fragmentShader ===" << std::endl;
    //std::cout << fragmentShader << std::endl;

    m_shader.addVertexShader(vertexShader);
    m_shader.addFragmentShader(fragmentShader);
    m_shader.compileShader();
}

void Game::input() {
    EngineInput::update();
    // read up key
    if (EngineInput::getKeyDown(SDLK_UP)) {
        std::cout << "Up Arrow Pressed" << std::endl;
    }
    if (EngineInput::getKeyUp(SDLK_UP)) {
        std::cout << "Up Arrow Released" << std::endl;
    }

    // read down key
    if (EngineInput::getKeyDown(SDLK_DOWN)) {
        std::cout << "Down Arrow Pressed" << std::endl;
    }
    if (EngineInput::getKeyUp(SDLK_DOWN)) {
        std::cout << "Down Arrow Released" << std::endl;
    }
    if (EngineInput::getMouseDown(SDL_BUTTON_LEFT)) {
        std::cout << "Left Click Down at " << EngineInput::getMousePosition() << std::endl;
    }
    if (EngineInput::getMouseUp(SDL_BUTTON_LEFT)) {
        std::cout << "Left Click Up at " << EngineInput::getMousePosition() << std::endl;
    }
}
void Game::update() {

}

void Game::render() {
    m_shader.bind();
    m_mesh.draw();
}

Game::~Game()
{

}

}
