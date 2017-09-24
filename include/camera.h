#ifndef CAMERA_H
#define CAMERA_H

#include "vector3f.h"
#include <memory>

namespace ogle {
class Camera
{
    public:
        Camera();
        Camera(Vector3f pos, Vector3f forward, Vector3f up);
        Camera(const Camera& other);
        Camera& operator=(const Camera& other);

        Vector3f& getPos() { return this->m_pos; }
        Vector3f getPos() const { return this->m_pos; }
        void setPos(Vector3f& pos) {
            this->m_pos = pos;
        }

        Vector3f& getForward() { return this->m_forward; }
        Vector3f getForward() const { return this->m_forward; }
        void setForward(Vector3f& forward) {
            this->m_forward = forward;
        }

        Vector3f& getUp() { return this->m_up; }
        Vector3f getUp() const { return this->m_up; }
        void setUp(Vector3f& up) {
            this->m_up = up;
        }

        void move(Vector3f& dir, float amt);
        std::shared_ptr<Vector3f> getLeft();
        std::shared_ptr<Vector3f> getRight();
        void rotateX(float angle);
        void rotateY(float angle);
        virtual ~Camera();

        static std::shared_ptr<Vector3f> yAxis;

    protected:

    private:


        Vector3f m_pos;
        Vector3f m_forward;
        Vector3f m_up;
};
}
#endif // CAMERA_H
