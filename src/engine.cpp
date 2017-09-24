#include "engine.h"
#include "window.h"
#include <iostream>
#include <thread>
#include "engine_time.h"
#include "engine_input.h"
#include "render_util.h"

#define FRAME_TIME 1.0 / FRAME_CAP

namespace ogle {
Engine::Engine(const int width, const int height, const std::string& title) : m_window(width, height, title), m_game(width, height)
{
    m_isRunning = false;
}

void Engine::start(int *argcp, char **argv) {
    if (m_isRunning)
        return;
    std::cout << "Bootstraping Engine" << std::endl;
    std::cout << "OpenGL Version: " << RenderUtil::getOpenGLVersion() << std::endl;

    EngineInput::init();

    m_isRunning = true;
    run();
}

void Engine::run() {

    Time startTime;
    int64_t passedTime = 0;
    double unprocessedTime = 0.0;
    int32_t frames = 0;
    int64_t frameCount = 0;

    while (m_isRunning) {
        bool renderScene = false;

        passedTime = startTime.getDeltaNano();
        startTime.markTime();
        unprocessedTime += passedTime / (double) SECOND;
        frameCount += passedTime;

        while (unprocessedTime > FRAME_TIME) {

            renderScene = true;
            unprocessedTime -= FRAME_TIME;

            if(m_window.isClosed()) {
                stop();
            }

            m_game.input();
            m_game.update();

            if (frameCount >= SECOND) {
                std::cout << "FPS: " << frames << std::endl;
                frames = 0;
                frameCount = 0;
            }
        }
        if (renderScene) {
            render();
            frames++;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
}

void Engine::render() {
    RenderUtil::clearScreen();
    m_game.render();
    m_window.Render();
}

void Engine::stop() {
    if (!m_isRunning)
        return;
    m_isRunning = false;
    std::cout << "Shutting Down Engine" << std::endl;
}

Engine::~Engine()
{

}
}
