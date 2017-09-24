#ifndef GAME_H
#define GAME_H

#include "mesh.h"
#include "shader.h"
#include "basicshader.h"
#include "phongshader.h"
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

        Vector2f m_mouseDownPosition;
        float m_xRot;
        float m_yRot;

        Mesh m_mesh;
        Transform m_transform;
        Camera m_camera;
        float m_temp;
};
}
#endif // GAME_H
