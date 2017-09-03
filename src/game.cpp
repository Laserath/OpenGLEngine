#include "game.h"

#include "engine_input.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "resource_loader.h"
#include <string>
#include <math.h>
#include "engine_time.h"

namespace ogle {

Game::Game(const int& width, const int& height)
{
    /*
    std::vector<Vertex> vertices = {};
    std::vector<int> indices = {0,1,3,
                                3,1,2,
                                2,1,0,
                                0,2,3};

    Vector3f vec3f_bl(-1.0f, -1.0f, 0.0f);
    Vector3f vec3f_tm( 0.0f,  1.0f, 0.0f);
    Vector3f vec3f_br( 1.0f, -1.0f, 0.0f);
    Vector3f vec3f_tp( 0.0f, -1.0f, 1.0f);
    vertices.push_back(Vertex(vec3f_bl));
    vertices.push_back(Vertex(vec3f_tm));
    vertices.push_back(Vertex(vec3f_br));
    vertices.push_back(Vertex(vec3f_tp));

    m_mesh.addVertices(vertices, indices);
    */
    std::vector<Mesh> meshes = *ResourceLoader::loadMesh("models/cube/newcube.obj");
    if (meshes.size() < 1) {
        std::cerr << "Unable to load mesh, no mesh returned" << std::endl;
        exit(1);
    }
    m_xRot = 0;
    m_yRot = 0;
    m_mesh = meshes[0];

    m_transform.setProjection(70.0, width + 0.0, height + 0.0, 0.1f, 1000.0);

    std::string vertexShader = *ResourceLoader::loadShader("shaders/basicVertex.vs");
    std::string fragmentShader = *ResourceLoader::loadShader("shaders/basicFragment.fs");

    m_shader.addVertexShader(vertexShader);
    m_shader.addFragmentShader(fragmentShader);
    m_shader.compileShader();

    m_shader.addUniform("trans");

}

void Game::input() {
    EngineInput::update();
    // read up key
    if (EngineInput::getKeyDown(SDLK_UP)) {
        //std::cout << "Up Arrow Pressed" << std::endl;
        m_xRot+=10;
    }
    if (EngineInput::getKeyUp(SDLK_UP)) {
        //std::cout << "Up Arrow Released" << std::endl;
    }

    // read down key
    if (EngineInput::getKeyDown(SDLK_DOWN)) {
        std::cout << "Down Arrow Pressed" << std::endl;
        m_xRot-=10;
    }
    if (EngineInput::getKeyUp(SDLK_DOWN)) {
        std::cout << "Down Arrow Released" << std::endl;
    }

    // read left key
    if (EngineInput::getKeyDown(SDLK_LEFT)) {
        std::cout << "Left Arrow Pressed" << std::endl;
        m_yRot-=10;
    }
    if (EngineInput::getKeyUp(SDLK_LEFT)) {
        std::cout << "Left Arrow Released" << std::endl;
    }

    // read right key
    if (EngineInput::getKeyDown(SDLK_RIGHT)) {
        std::cout << "Right Arrow Pressed" << std::endl;
        m_yRot+=10;
    }
    if (EngineInput::getKeyUp(SDLK_RIGHT)) {
        std::cout << "Right Arrow Released" << std::endl;
    }

    // read mouse left button
    if (EngineInput::getMouseDown(SDL_BUTTON_LEFT)) {
        std::cout << "Left Click Down at " << EngineInput::getMousePosition() << std::endl;
    }
    if (EngineInput::getMouseUp(SDL_BUTTON_LEFT)) {
        std::cout << "Left Click Up at " << EngineInput::getMousePosition() << std::endl;
    }
}

void Game::update() {
    static Time uniformTime;
    m_temp = uniformTime.getDelta() * .000000001;
    float sinTemp = sin(m_temp);

    m_transform.setTranslation(0.0f, 0.0f, 5.0f);
    m_transform.setRotation(m_xRot, m_yRot, 0);
    //m_transform.setScale(sinTemp,sinTemp,sinTemp);
    m_shader.setUniform("trans", *m_transform.getProjectedTransformation());
}

void Game::render() {
    m_shader.bind();

    m_mesh.draw();
}

Game::~Game()
{

}

}
