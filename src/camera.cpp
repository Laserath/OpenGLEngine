#include "camera.h"

namespace ogle {

Camera::Camera() : m_pos(0,0,0), m_forward(0,0,1), m_up(0,1,0) { }

Camera::Camera(Vector3f pos, Vector3f forward, Vector3f up)
{
    m_pos = pos;
    m_forward = forward;
    m_up = up;

    this->m_forward.normalize();
    this->m_up.normalize();
}

Camera::Camera(const Camera& other) {
    m_pos = other.getPos();
    m_forward = other.getForward();
    m_up = other.getUp();
}

Camera& Camera::operator=(const Camera& other) {
    m_pos = other.getPos();
    m_forward = other.getForward();
    m_up = other.getUp();
}

void Camera::move(Vector3f& dir, float amt) {
    m_pos = *m_pos.add(*dir.multiply(amt));
}

std::shared_ptr<Vector3f> Camera::getLeft() {
    std::shared_ptr<Vector3f> left = m_forward.cross(m_up);
    left->normalize();
    return left;
}

std::shared_ptr<Vector3f> Camera::getRight() {
    std::shared_ptr<Vector3f> right = m_up.cross(m_forward);
    right->normalize();
    return right;
}

void Camera::rotateX(float angle) {
    Vector3f Haxis = *yAxis->cross(m_forward);
    Haxis.normalize();

    m_forward.rotate(angle, Haxis);
    m_forward.normalize();

    m_up = *m_forward.cross(Haxis);
    m_up.normalize();
}

void Camera::rotateY(float angle) {
    Vector3f Haxis = *yAxis->cross(m_forward);
    Haxis.normalize();

    m_forward.rotate(angle, *yAxis);
    m_forward.normalize();

    m_up = *m_forward.cross(Haxis);
    m_up.normalize();
}

Camera::~Camera()
{

}

std::shared_ptr<Vector3f> Camera::yAxis = std::make_shared<Vector3f>(0,1,0);

}
