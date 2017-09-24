#include "point_light.h"

namespace ogle {
PointLight::PointLight()
{
    //TODO
}

PointLight::PointLight(BaseLight& base, Attenuation& atten, Vector3f& position)
{
    this->m_base = base;
    this->m_atten = atten;
    this->m_position = position;
}

PointLight::PointLight(const PointLight& other)
{
    this->m_base = other.getBaseLight();
    this->m_atten = other.getAtten();
    this->m_position = other.getPosition();
}

PointLight& PointLight::operator=(const PointLight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->m_atten = rhs.getAtten();
    this->m_base = rhs.getBaseLight();
    this->m_position = rhs.getPosition();
    return *this;
}

PointLight::~PointLight()
{

}

}
