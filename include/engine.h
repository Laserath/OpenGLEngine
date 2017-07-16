#ifndef ENGINE_H
#define ENGINE_H

#include "window.h"
#include "game.h"

#define FRAME_CAP 5000

namespace ogle {
class Engine
{
    public:
        Engine(const int width, const int height, const std::string& title);
        virtual ~Engine();
        void start(int *argcp, char **argv);
        void stop();

    protected:

    private:
        Engine(const Engine& other) : m_window(other.getWindow()) { }
        void operator=(const Engine& other) { }
        Window getWindow() const { return m_window; }
        void run();
        void render();

        Window m_window;
        bool m_isRunning;
        Game m_game;

};
}

#endif // ENGINE_H
