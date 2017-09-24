#include "baselight.h"

namespace ogle {
BaseLight::BaseLight(): m_color(0.0f, 0.0f, 0.0f)
{
    this->m_intensity = 0.0f;
}

BaseLight::BaseLight(Vector3f& color, float intensity)
{
    this->m_color = color;
    this->m_intensity = intensity;
}


BaseLight::BaseLight(const BaseLight& other)
{
    this->m_color = other.getColor();
    this->m_intensity = other.getIntensity();
}

BaseLight& BaseLight::operator=(const BaseLight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->m_color = rhs.getColor();
    this->m_intensity = rhs.getIntensity();
    return *this;
}

BaseLight::~BaseLight()
{
    //dtor
}
}

