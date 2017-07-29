#ifndef GAME_H
#define GAME_H

#include "mesh.h"
#include "shader.h"

namespace ogle {
class Game
{
    public:
        Game();
        void input();
        void update();
        void render();
        virtual ~Game();

    protected:

    private:
        Game(const Game& other) { }
        void operator=(const Game& other) { }

        Mesh m_mesh;
        Shader m_shader;
};
}
#endif // GAME_H
