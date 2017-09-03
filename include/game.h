#ifndef GAME_H
#define GAME_H

#include "mesh.h"
#include "shader.h"
#include "transform.h"

namespace ogle {
class Game
{
    public:
        Game(const int& width, const int& height);
        Game(const Game& other) { }
        void input();
        void update();
        void render();
        virtual ~Game();

    protected:

    private:
        void operator=(const Game& other) { }

        int m_xRot;
        int m_yRot;

        Mesh m_mesh;
        Shader m_shader;
        Transform m_transform;
        float m_temp;
};
}
#endif // GAME_H
