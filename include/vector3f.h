#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <iostream>
#include <memory>
#include <glm/glm.hpp>

#define DEGREE_TO_RADIANS M_PI / 180

namespace ogle {
class Vector3f
{
    public:
        Vector3f();
        Vector3f(const float x, const float y, const float z);
        Vector3f(const Vector3f& other);
        Vector3f& operator=(const Vector3f& other);

        virtual ~Vector3f();

        float getX() const;
        float getX();
        void setX(const float x);
        float getY() const;
        float getY();
        void setY(const float y);
        float getZ() const;
        float getZ();
        void setZ(const float z);

        inline std::shared_ptr<glm::vec3> asGLMVec() { return std::make_shared<glm::vec3>(getX(), getY(), getZ()); }

        float length() const;
        float length();

        float dot(const Vector3f& r) const;
        float dot(const Vector3f& r);

        std::shared_ptr<Vector3f> cross(const Vector3f& r) const;
        std::shared_ptr<Vector3f> cross(const Vector3f& r);

        std::shared_ptr<Vector3f> normalize();
        Vector3f rotate(const float angle, Vector3f axis);
        std::shared_ptr<Vector3f> add(const Vector3f& r);
        std::shared_ptr<Vector3f> add(const float r);
        std::shared_ptr<Vector3f> subtract(const Vector3f& r);
        std::shared_ptr<Vector3f> subtract(const float r);
        std::shared_ptr<Vector3f> multiply(const Vector3f& r);
        std::shared_ptr<Vector3f> multiply(const float r);
        std::shared_ptr<Vector3f> divide(const Vector3f& r);
        std::shared_ptr<Vector3f> divide(const float r);
        std::shared_ptr<Vector3f> absolute();

    protected:

    private:

        float m_x;
        float m_y;
        float m_z;
};

std::ostream& operator<<(std::ostream& os, const Vector3f& vector3f);

}
#endif // VECTOR3F_H
