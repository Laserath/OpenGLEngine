#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <iostream>
#include <memory>

namespace ogle {

class Vector2f
{
    public:
        Vector2f(float x, float y);
        Vector2f(const Vector2f& other);

        float getX() const { return this->m_x; }
        float getY() const { return this->m_y; }
        void setX(float x) { this->m_x = x; }
        void setY(float y) { this->m_y = y; }

        float length() const;
        float length();

        float dot(const Vector2f& r) const;
        float dot(const Vector2f& r);

        std::shared_ptr<Vector2f> normalize();
        std::shared_ptr<Vector2f> rotate(const float angle);
        std::shared_ptr<Vector2f> add(const Vector2f& r);
        std::shared_ptr<Vector2f> add(const float r);
        std::shared_ptr<Vector2f> subtract(const Vector2f& r);
        std::shared_ptr<Vector2f> subtract(const float r);
        std::shared_ptr<Vector2f> multiply(const Vector2f& r);
        std::shared_ptr<Vector2f> multiply(const float r);
        std::shared_ptr<Vector2f> divide(const Vector2f& r);
        std::shared_ptr<Vector2f> divide(const float r);


        virtual ~Vector2f();

    protected:

    private:

        void operator=(const Vector2f& other) { }

        float m_x;
        float m_y;
};

std::ostream& operator<<(std::ostream& os, const Vector2f& vector2f);

}
#endif // VECTOR2F_H
