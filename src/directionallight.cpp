#include "directionallight.h"

namespace ogle {
DirectionalLight::DirectionalLight(): m_direction(0.0f, 0.0f, 0.0f)
{

}

DirectionalLight::DirectionalLight(BaseLight& base, Vector3f& direction)
{
    this->m_base = base;
    this->m_direction = *direction.normalize();
}

DirectionalLight::DirectionalLight(const DirectionalLight& other)
{
    this->m_base = other.getBase();
    this->m_direction = other.getDirection();
}

DirectionalLight& DirectionalLight::operator=(const DirectionalLight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->m_base = rhs.getBase();
    this->m_direction = rhs.getDirection();
    return *this;
}

DirectionalLight::~DirectionalLight()
{

}
}


