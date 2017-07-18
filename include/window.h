#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>

namespace ogle {
class Window
{
    public:
        Window(const int width, const int height, const std::string& title);
        Window(const Window& other);
        virtual ~Window();
        void Render();
        bool isClosed();

    protected:

    private:
        void operator=(const Window& other) { }

        bool m_isClosed;
        SDL_Window* m_window;
        SDL_GLContext m_glContext;

        int m_width;
        int m_height;
        std::string m_title;
};
}

#endif // WINDOW_H
