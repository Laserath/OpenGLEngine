#ifndef QUATERNION_H
#define QUATERNION_H

#include <memory>
#include "vector3f.h"

namespace ogle {
class Quaternion: std::enable_shared_from_this<Quaternion>
{
    public:
        Quaternion(const float x, const float y, const float z, const float w) {
            this->m_x = x;
            this->m_y = y;
            this->m_z = z;
            this->m_w = w;
        }

        float getX() { return this->m_x; }
        float getY() { return this->m_y; }
        float getZ() { return this->m_z; }
        float getW() { return this->m_w; }
        float getX() const { return this->m_x; }
        float getY() const { return this->m_y; }
        float getZ() const { return this->m_z; }
        float getW() const { return this->m_w; }
        void setX(const float x) { this->m_x = x; }
        void setY(const float y) { this->m_y = y; }
        void setZ(const float z) { this->m_z = z; }
        void setW(const float w) { this->m_w = w; }

        float length();
        std::shared_ptr<Quaternion> normalize();
        std::shared_ptr<Quaternion> conjugate();
        std::shared_ptr<Quaternion> multiply(const Quaternion& r);
        std::shared_ptr<Quaternion> multiply(const Vector3f& r);

        Quaternion(const Quaternion& other);
        virtual ~Quaternion();

    protected:

    private:
        void operator=(const Quaternion& other) { }

        float m_x;
        float m_y;
        float m_z;
        float m_w;
};

}
#endif // QUATERNION_H
