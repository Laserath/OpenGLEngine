#include "quaternion.h"

#include <cmath>

namespace ogle {
Quaternion::Quaternion(const Quaternion& other)
{
    this->m_x = other.getX();
    this->m_y = other.getY();
    this->m_z = other.getZ();
    this->m_w = other.getW();
}

float Quaternion::length() {
    return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ() + getW() * getW());
}

std::shared_ptr<Quaternion> Quaternion::normalize() {
    float len = length();

    setX(getX() / len);
    setY(getY() / len);
    setZ(getZ() / len);
    setW(getW() / len);

    return shared_from_this();
}

std::shared_ptr<Quaternion> Quaternion::conjugate() {
    return std::make_shared<Quaternion>(-getX(), -getY(), -getZ(), getW());
}

std::shared_ptr<Quaternion> Quaternion::multiply(const Quaternion& r) {
    float x = getX() * r.getW() + getW() * r.getX() + getY() * r.getZ() - getZ() * r.getY();
    float y = getY() * r.getW() + getW() * r.getY() + getZ() * r.getX() - getX() * r.getZ();
    float z = getZ() * r.getW() + getW() * r.getZ() + getX() * r.getY() - getY() * r.getX();
    float w = getW() * r.getW() - getX() * r.getX() - getY() * r.getY() - getZ() * r.getZ();

    return std::make_shared<Quaternion>(x,y,z,w);
}

std::shared_ptr<Quaternion> Quaternion::multiply(const Vector3f& r) {
    float w = -getX() * r.getX() - getY() * r.getY() - getZ() * r.getZ();
    float x =  getW() * r.getX() + getY() * r.getZ() - getZ() * r.getY();
    float y =  getW() * r.getY() + getZ() * r.getX() - getX() * r.getZ();
    float z =  getW() * r.getZ() + getX() * r.getY() - getY() * r.getX();

    return std::make_shared<Quaternion>(x,y,z,w);
}

Quaternion::~Quaternion()
{
    //dtor
}

}
