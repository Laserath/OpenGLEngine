#include "vector3f.h"

#include <cmath>
#include <cstdlib>
#include "quaternion.h"

#define RADIAN_CONVERSION M_PI / 180.0

namespace ogle {

Vector3f::Vector3f() {
    setX(0.0f);
    setY(0.0f);
    setZ(0.0f);
}

Vector3f::Vector3f(const float x, const float y, const float z)
{
    setX(x);
    setY(y);
    setZ(z);
}

Vector3f::Vector3f(const Vector3f& other)
{
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());
}

Vector3f& Vector3f::operator=(const Vector3f& other) {
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());

    return *this;
}

float Vector3f::getX() const {
    return this->m_x;
}

float Vector3f::getX() {
    return this->m_x;
}

void Vector3f::setX(const float x) {
    if (x == -0) {
        this->m_x = 0;
    } else {
        this->m_x = x;
    }
}

float Vector3f::getY() const {
    return this->m_y;
}

float Vector3f::getY() {
    return this->m_y;
}

void Vector3f::setY(const float y) {
    if (y == -0) {
        this->m_y = 0;
    } else {
        this->m_y = y;
    }
}

float Vector3f::getZ() const {
    return this->m_z;
}

float Vector3f::getZ() {
    return this->m_z;
}

void Vector3f::setZ(const float z) {
    if (z == -0) {
        this->m_z = 0;
    } else {
        this->m_z = z;
    }
}

float Vector3f::length() {
    return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

float Vector3f::length() const {
    return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

float Vector3f::dot(const Vector3f& r) const {
    return getX() * r.getX() + getY() * r.getY() + getZ() * r.getZ();
}

float Vector3f::dot(const Vector3f& r) {
    return getX() * r.getX() + getY() * r.getY() + getZ() * r.getZ();
}

std::shared_ptr<Vector3f> Vector3f::cross(const Vector3f& r) const {
    float x = getY() * r.getZ() - getZ() * r.getY();
    float y = getZ() * r.getX() - getX() * r.getZ();
    float z = getX() * r.getY() - getY() * r.getX();

    return std::make_shared<Vector3f>(x, y, z);
}

std::shared_ptr<Vector3f> Vector3f::cross(const Vector3f& r) {
    float x = getY() * r.getZ() - getZ() * r.getY();
    float y = getZ() * r.getX() - getX() * r.getZ();
    float z = getX() * r.getY() - getY() * r.getX();

    return std::make_shared<Vector3f>(x, y, z);
}

std::shared_ptr<Vector3f> Vector3f::normalize() {
    float vecLength = length();
    float x = getX() / vecLength;
    float y = getY() / vecLength;
    float z = getZ() / vecLength;

    return std::make_shared<Vector3f>(x, y, z);
}

Vector3f Vector3f::rotate(const float angle, Vector3f axis) {
    float sinHalfAngle = sin(angle * RADIAN_CONVERSION * .5);
    float cosHalfAngle = cos(angle * RADIAN_CONVERSION * .5);

    float rX = axis.getX() * sinHalfAngle;
    float rY = axis.getY() * sinHalfAngle;
    float rZ = axis.getZ() * sinHalfAngle;
    float rW = cosHalfAngle;

    Quaternion rotation = Quaternion(rX, rY, rZ, rW);
    Quaternion conjugate = *rotation.conjugate();

    Quaternion w = *rotation.multiply(*this)->multiply(conjugate);
    setX(w.getX());
    setY(w.getY());
    setZ(w.getZ());

    return *this;
}

std::shared_ptr<Vector3f> Vector3f::add(const Vector3f& r) {
    return std::make_shared<Vector3f>(getX() + r.getX(), getY() + r.getY(), getZ() + r.getZ());
}

std::shared_ptr<Vector3f> Vector3f::add(const float r) {
    return std::make_shared<Vector3f>(getX() + r, getY() + r, getZ() + r);
}

std::shared_ptr<Vector3f> Vector3f::subtract(const Vector3f& r) {
    return std::make_shared<Vector3f>(getX() - r.getX(), getY() - r.getY(), getZ() - r.getZ());
}

std::shared_ptr<Vector3f> Vector3f::subtract(const float r) {
    return std::make_shared<Vector3f>(getX() - r, getY() - r, getZ() - r);
}

std::shared_ptr<Vector3f> Vector3f::multiply(const Vector3f& r) {
    return std::make_shared<Vector3f>(getX() * r.getX(), getY() * r.getY(), getZ() * r.getZ());
}

std::shared_ptr<Vector3f> Vector3f::multiply(const float r) {
    return std::make_shared<Vector3f>(getX() * r, getY() * r, getZ() * r);
}

std::shared_ptr<Vector3f> Vector3f::divide(const Vector3f& r) {
    return std::make_shared<Vector3f>(getX() / r.getX(), getY() / r.getY(), getZ() / r.getZ());
}

std::shared_ptr<Vector3f> Vector3f::divide(const float r) {
    return std::make_shared<Vector3f>(getX() / r, getY() / r, getZ() / r);
}

std::shared_ptr<Vector3f> Vector3f::absolute() {
    return std::make_shared<Vector3f>(abs(getX()), abs(getY()), abs(getZ()));
}

Vector3f::~Vector3f()
{

}

std::ostream& operator<<(std::ostream& os, const Vector3f& vector3f) {
    os << "(" << vector3f.getX() << " " << vector3f.getY() << " " << vector3f.getZ() << ")";
    return os;
}


}
