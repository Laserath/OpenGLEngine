#include "vector2f.h"

#include <cmath>

#define DEGREE_TO_RADIANS M_PI / 180

namespace ogle {
Vector2f::Vector2f(float x, float y)
{

    this->m_x = x;
    this->m_y = y;
}

Vector2f::Vector2f(const Vector2f& other) {
    this->m_x = other.m_x;
    this->m_y = other.m_y;
}

float Vector2f::length() {
    return sqrt(getX() * getX() + getY() * getY());
}

float Vector2f::length() const {
    return sqrt(getX() * getX() + getY() * getY());
}

float Vector2f::dot(const Vector2f& r) const {
    return getX() * r.getX() + getY() * r.getY();
}

float Vector2f::dot(const Vector2f& r) {
    return getX() * r.getX() + getY() * r.getY();
}

std::shared_ptr<Vector2f> Vector2f::normalize() {
    float vecLength = length();
    float x = getX() / vecLength;
    float y = getY() / vecLength;

    return std::make_shared<Vector2f>(x, y);
}

std::shared_ptr<Vector2f> Vector2f::rotate(const float angle) {
    double rad = angle * DEGREE_TO_RADIANS;
    double cosine = cos(rad);
    double sine = sin(rad);

    return std::make_shared<Vector2f>((float)(getX() * cosine - getY() * sine), (float)(getX() * sine + getY() * cosine));
}

std::shared_ptr<Vector2f> Vector2f::add(const Vector2f& r) {
    return std::make_shared<Vector2f>(getX() + r.getX(), getY() + r.getY());
}

std::shared_ptr<Vector2f> Vector2f::add(const float r) {
    return std::make_shared<Vector2f>(getX() + r, getY() + r);
}

std::shared_ptr<Vector2f> Vector2f::subtract(const Vector2f& r) {
    return std::make_shared<Vector2f>(getX() - r.getX(), getY() - r.getY());
}

std::shared_ptr<Vector2f> Vector2f::subtract(const float r) {
    return std::make_shared<Vector2f>(getX() - r, getY() - r);
}

std::shared_ptr<Vector2f> Vector2f::multiply(const Vector2f& r) {
    return std::make_shared<Vector2f>(getX() * r.getX(), getY() * r.getY());
}

std::shared_ptr<Vector2f> Vector2f::multiply(const float r) {
    return std::make_shared<Vector2f>(getX() * r, getY() * r);
}

std::shared_ptr<Vector2f> Vector2f::divide(const Vector2f& r) {
    return std::make_shared<Vector2f>(getX() / r.getX(), getY() / r.getY());
}

std::shared_ptr<Vector2f> Vector2f::divide(const float r) {
    return std::make_shared<Vector2f>(getX() / r, getY() / r);
}

std::ostream& operator<<(std::ostream& os, const Vector2f& vector2f) {
    os << "(" << vector2f.getX() << " " << vector2f.getY() << ")";
    return os;
}

Vector2f::~Vector2f()
{

}

}
