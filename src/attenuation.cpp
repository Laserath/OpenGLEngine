#include "attenuation.h"

namespace ogle {
Attenuation::Attenuation(): Attenuation(0.0f, 0.0f, 0.0f) { }

Attenuation::Attenuation(float constant, float linear, float exponent)
{
    this->m_constant = constant;
    this->m_linear = linear;
    this->m_exponent = exponent;
}

Attenuation::Attenuation(const Attenuation& other)
{
    this->m_constant = other.getConstant();
    this->m_linear = other.getLinear();
    this->m_exponent = other.getExponent();
}

Attenuation& Attenuation::operator=(const Attenuation& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->m_constant = rhs.getConstant();
    this->m_linear = rhs.getLinear();
    this->m_exponent = rhs.getExponent();
    return *this;
}

Attenuation::~Attenuation()
{

}

}
