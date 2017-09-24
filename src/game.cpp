#include "game.h"

#include "engine_input.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "resource_loader.h"
#include <string>
#include <math.h>
#include "engine_time.h"
#include "point_light.h"

namespace ogle {

Game::Game(const int& width, const int& height)
{
    std::vector<Mesh> meshes = *ResourceLoader::loadMesh("models/textured_cube/textured_cube.obj");
    if (meshes.size() < 1) {
        std::cerr << "Unable to load mesh, no mesh returned" << std::endl;
        exit(1);
    }
    m_xRot = 0.0f;
    m_yRot = 0.0f;

    m_mesh = meshes[0];
    m_transform.setProjection(70.0, width + 0.0, height + 0.0, 0.1f, 1000.0);
    m_transform.setCamera(m_camera);

    Vector3f ambientLight = Vector3f(0.1,0.1,0.1);
    PhongShader::getInstance()->setAmbientLight(ambientLight);
    PhongShader::getInstance()->getDirectionalLight().getBase().setIntensity(0.3f);
    Vector3f direction = Vector3f(-1,1,-1);
    PhongShader::getInstance()->getDirectionalLight().setDirection(direction);

    PointLight pLight1;
    Vector3f pLight1Color = Vector3f(1, 0, 0);
    Attenuation pLight1Atten = Attenuation(0, 0, 1);
    Vector3f pLight1Position = Vector3f(-2, 0, 3);

    pLight1.getBaseLight().setColor(pLight1Color);
    pLight1.getBaseLight().setIntensity(0.8f);
    pLight1.setPosition(pLight1Position);
    pLight1.setAtten(pLight1Atten);

    PointLight pLight2;
    Vector3f pLight2Color = Vector3f(0, 0, 1);
    Attenuation pLight2Atten = Attenuation(0, 0, 1);
    Vector3f pLight2Position = Vector3f(2, 0, 7);

    pLight2.getBaseLight().setColor(pLight2Color);
    pLight2.getBaseLight().setIntensity(0.8f);
    pLight2.setPosition(pLight2Position);
    pLight2.setAtten(pLight2Atten);

    PhongShader::addPointLight(pLight1);
    PhongShader::addPointLight(pLight2);
}

void Game::input() {

    EngineInput::update();
    static Time updateTime;
    m_temp = updateTime.getDelta() * 20;
    updateTime.markTime();

    // read up key
    if (EngineInput::getKey(SDLK_UP)) {
        m_xRot += m_temp * 3;
    }

    // read down key
    if (EngineInput::getKey(SDLK_DOWN)) {
        m_xRot-= m_temp * 3;
    }

    // read left key
    if (EngineInput::getKey(SDLK_LEFT)) {
        m_yRot-= m_temp * 3;
    }

    // read right key
    if (EngineInput::getKey(SDLK_RIGHT)) {
        m_yRot+= m_temp * 3;
    }

    // read WASD keys
    if (EngineInput::getKey(SDLK_w)) {
        m_camera.move(m_camera.getForward(), 1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_s)) {
        m_camera.move(m_camera.getForward(), -1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_a)) {
        m_camera.move(*m_camera.getLeft(), 1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_d)) {
        m_camera.move(*m_camera.getRight(), 1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_q)) {
        m_camera.rotateY(1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_e)) {
        m_camera.rotateY(-1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_f)) {
        m_camera.rotateX(1 * m_temp);
    }

    if (EngineInput::getKey(SDLK_r)) {
        m_camera.rotateX(-1 * m_temp);
    }

    // read mouse left button
    if (EngineInput::getMouseDown(SDL_BUTTON_LEFT)) {
        m_mouseDownPosition = EngineInput::getMousePosition();
    }

    if (EngineInput::getMouse(SDL_BUTTON_LEFT)) {
        Vector2f newMousePosition = EngineInput::getMousePosition();

        float sensitivity = .2;
        float xDiff = m_mouseDownPosition.getX() - newMousePosition.getX();
        float yDiff = m_mouseDownPosition.getY() - newMousePosition.getY();
        m_camera.rotateX(yDiff * sensitivity);
        m_camera.rotateY(xDiff * sensitivity);

        m_mouseDownPosition = newMousePosition;
        //std::cout << "Left Click Down at " << EngineInput::getMousePosition() << std::endl;
    }
}

void Game::update() {
    static Time uniformTime;
    m_temp = uniformTime.getDeltaNano() * .000000001;
    float sinTemp = sin(m_temp);

    m_transform.setTranslation(sinTemp, sinTemp, 5.0f);
    m_transform.setRotation(m_xRot, m_yRot, 0);
    m_transform.setCamera(m_camera);
    //m_transform.setScale(sinTemp,sinTemp,sinTemp);
}

void Game::render() {
    PhongShader::getInstance()->bind();
    PhongShader::getInstance()->updateUniforms(*m_transform.getTransformation(), *m_transform.getProjectedTransformation(), m_mesh, m_transform);
    m_mesh.draw();
}

Game::~Game()
{

}

}
