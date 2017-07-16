#include "game.h"

#include "engine_input.h"
#include <iostream>
#include <SDL2/SDL.h>

using namespace ogle;

Game::Game()
{

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

}

Game::~Game()
{

}


