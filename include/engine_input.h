#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

#include <vector>
#include <cstdint>
#include <SDL2/SDL.h>
#include "vector2f.h"

namespace ogle {
class EngineInput
{
    public:
        EngineInput();
        static void init();
        static void update();

        static bool getKey(const SDL_Keycode& key);
        static bool getKeyDown(const SDL_Keycode& key);
        static bool getKeyUp(const SDL_Keycode& key);

        // These should use the mouse button macros
        // such as SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE etc.
        static bool getMouse(const Uint8 mouseButton);
        static bool getMouseDown(const Uint8 mouseButton);
        static bool getMouseUp(const Uint8 mouseButton);
        static Vector2f getMousePosition();

        virtual ~EngineInput();

    protected:

    private:
        EngineInput(const EngineInput& other) { }
        void operator=(const EngineInput& other) { }
        static void keyDown(const SDL_KeyboardEvent& event);
        static void keyUp(const SDL_KeyboardEvent& event);
        static void mouseDown(const SDL_MouseButtonEvent& event);
        static void mouseUp(const SDL_MouseButtonEvent& event);

        static std::vector<SDL_Keycode> currentKeys;
        static std::vector<SDL_Keycode> downKeys;
        static std::vector<SDL_Keycode> upKeys;

        static std::vector<Uint8> currentMouse;
        static std::vector<Uint8> downMouse;
        static std::vector<Uint8> upMouse;

    enum KeyState {
        UP,
        DOWN
    };
};
}

#endif // ENGINE_INPUT_H
