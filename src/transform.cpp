#include "transform.h"

namespace ogle {
Transform::Transform(): m_translation(0,0,0), m_rotation(0,0,0), m_scale(1,1,1)
{ }

Transform::Transform(Transform& other): m_translation(0,0,0), m_rotation(0,0,0), m_scale(1,1,1)
{
    this->setTranslation(other.getTranslation());
}

std::shared_ptr<Matrix4f> Transform::getTransformation() {
    std::shared_ptr<Matrix4f> translation = std::make_shared<Matrix4f>();
    std::shared_ptr<Matrix4f> rotation = std::make_shared<Matrix4f>();
    std::shared_ptr<Matrix4f> scale = std::make_shared<Matrix4f>();

    translation->initTranslation(getTranslation().getX(), getTranslation().getY(), getTranslation().getZ());
    rotation->initRotation(getRotation().getX(), getRotation().getY(), getRotation().getZ());
    scale->initScale(getScale().getX(), getScale().getY(), getScale().getZ());

    return translation->multiply(*(rotation->multiply(*scale)));
}

std::shared_ptr<Matrix4f> Transform::getProjectedTransformation() {
    std::shared_ptr<Matrix4f> transformationMatrix = getTransformation();
    std::shared_ptr<Matrix4f> projectionMatrix = std::make_shared<Matrix4f>();
    projectionMatrix->initProjection(m_fov, m_width, m_height, m_zNear, m_zFar);
    return projectionMatrix->multiply(*transformationMatrix);
}

float Transform::m_zNear;
float Transform::m_zFar;
float Transform::m_width;
float Transform::m_height;
float Transform::m_fov;

Transform::~Transform()
{
    //dtor
}


}
