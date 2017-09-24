#include "material.h"

namespace ogle {

Material::Material() {
    this->m_color.setX(1.0f);
    this->m_color.setY(1.0f);
    this->m_color.setZ(1.0f);

    this->m_specularIntensity = 1.0f;
    this->m_specularPower = 8.0f;
}

Material::Material(Texture& texture, Vector3f& color) : Material(texture, color, 4.0f, 32.0f) { }

Material::Material(Texture& texture, Vector3f& color, float specularIntensity, float specularPower)
{
    this->m_texture = texture;
    this->m_color = color;
    this->m_specularIntensity = specularIntensity;
    this->m_specularPower = specularPower;
}

Material::Material(const Material& other)
{
    this->m_texture = other.getTexture();
    this->m_color = other.getColor();
    this->m_specularIntensity = other.getSpecularIntensity();
    this->m_specularPower = other.getSpecularPower();
}

Material& Material::operator=(const Material& rhs)
{
    this->m_texture = rhs.getTexture();
    this->m_color = rhs.getColor();
    this->m_specularIntensity = rhs.getSpecularIntensity();
    this->m_specularPower = rhs.getSpecularPower();
    return *this;
}

Material::~Material()
{

}

}
