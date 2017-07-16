#include "engine_input.h"

#include <algorithm>
#include <SDL2/SDL.h>
#include <iostream>

namespace ogle {



std::vector<SDL_Keycode> EngineInput::currentKeys = {};
std::vector<SDL_Keycode> EngineInput::downKeys = {};
std::vector<SDL_Keycode> EngineInput::upKeys = {};

std::vector<Uint8> EngineInput::currentMouse = {};
std::vector<Uint8> EngineInput::downMouse = {};
std::vector<Uint8> EngineInput::upMouse = {};

EngineInput::EngineInput()
{

}

void EngineInput::init() {

}

void EngineInput::update() {
    EngineInput::downKeys.clear();
    EngineInput::downMouse.clear();
    EngineInput::upKeys.clear();
    EngineInput::upMouse.clear();
    SDL_Event event;

    std::vector<SDL_Event> requeueEvents = { };
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            keyDown(event.key);
            break;
        case SDL_KEYUP:
            keyUp(event.key);
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseDown(event.button);
            break;
        case SDL_MOUSEBUTTONUP:
            mouseUp(event.button);
            break;
        case SDL_QUIT:
            // this is needed else where, we will just drop the other events on the floor
            // until we decide we need them
            requeueEvents.push_back(event);
            break;
        default:
            break;
        }
    }
    for (SDL_Event requeue : requeueEvents) {
        SDL_PushEvent(&requeue);
    }
}

bool EngineInput::getKey(const SDL_Keycode& key) {
    std::vector<SDL_Keycode>::iterator keyStroke =
        std::find(EngineInput::currentKeys.begin(),
                  EngineInput::currentKeys.end(),
                  key);
    return keyStroke != EngineInput::currentKeys.end();
}

bool EngineInput::getKeyDown(const SDL_Keycode& key) {
    std::vector<SDL_Keycode>::iterator keyStroke =
        std::find(EngineInput::downKeys.begin(),
                  EngineInput::downKeys.end(),
                  key);
    return keyStroke != EngineInput::downKeys.end();
}

bool EngineInput::getKeyUp(const SDL_Keycode& key) {
    std::vector<SDL_Keycode>::iterator keyStroke =
        std::find(EngineInput::upKeys.begin(),
                  EngineInput::upKeys.end(),
                  key);
    return keyStroke != EngineInput::upKeys.end();
}

bool EngineInput::getMouse(const Uint8 mouseButton) {
    std::vector<Uint8>::iterator button =
        std::find(EngineInput::currentMouse.begin(),
                  EngineInput::currentMouse.end(),
                  mouseButton);
    return button != EngineInput::currentMouse.end();
}

bool EngineInput::getMouseDown(const Uint8 mouseButton) {
    std::vector<Uint8>::iterator button =
        std::find(EngineInput::downMouse.begin(),
                  EngineInput::downMouse.end(),
                  mouseButton);
    return button != EngineInput::downMouse.end();
}

bool EngineInput::getMouseUp(const Uint8 mouseButton) {
    std::vector<Uint8>::iterator button =
        std::find(EngineInput::upMouse.begin(),
                  EngineInput::upMouse.end(),
                  mouseButton);
    return button != EngineInput::upMouse.end();
}

Vector2f EngineInput::getMousePosition() {
    int x,y;
    SDL_GetMouseState(&x, &y);
    return Vector2f(x,y);
}

EngineInput::~EngineInput()
{

}

void EngineInput::keyDown(const SDL_KeyboardEvent& event) {
    // key repeats trigger events too
    if (!event.repeat) {
        // key pressed, track that it was pressed
        EngineInput::downKeys.push_back(event.keysym.sym);    // for this frame
        EngineInput::currentKeys.push_back(event.keysym.sym); // that it is down
    }
}

void EngineInput::keyUp(const SDL_KeyboardEvent& event) {
    // key released, track that it was released and clean up other areas
    EngineInput::upKeys.push_back(event.keysym.sym); // track released for this frame

    // clean up from a vector is a bit involved
    std::vector<SDL_Keycode>::iterator foundItem =
        std::find(EngineInput::currentKeys.begin(),
                  EngineInput::currentKeys.end(),
                  event.keysym.sym);

    if (foundItem != EngineInput::currentKeys.end()) {
        // swap to end for O(1) removal
        std::swap(*foundItem, EngineInput::currentKeys.back());
        // remove item which is now at end of list
        EngineInput::currentKeys.pop_back();
    }
}

void EngineInput::mouseDown(const SDL_MouseButtonEvent& event) {
    EngineInput::downMouse.push_back(event.button);
    EngineInput::currentMouse.push_back(event.button);
}

void EngineInput::mouseUp(const SDL_MouseButtonEvent& event) {
    EngineInput::upMouse.push_back(event.button);

    // clean up from a vector is a bit involved
    std::vector<Uint8>::iterator foundButton =
        std::find(EngineInput::currentMouse.begin(),
                  EngineInput::currentMouse.end(),
                  event.button);
    if (foundButton != EngineInput::currentMouse.end()) {
        // swap to end for O(1) removal
        std::swap(*foundButton, EngineInput::currentMouse.back());
        // remove item which is now at end of list
        EngineInput::currentMouse.pop_back();
    }
}


}
