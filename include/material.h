#ifndef MATERIAL_H
#define MATERIAL_H

#include "texture.h"
#include "vector3f.h"

namespace ogle {
class Material
{
    public:
        Material();
        Material(Texture& texture, Vector3f& color);
        Material(Texture& texture, Vector3f& color, float specularIntensity, float specularPower);
        Material(const Material& other);
        Material& operator=(const Material& other);

        Texture& getTexture() { return this->m_texture; }
        Texture getTexture() const { return this->m_texture; }
        void setTexture(const Texture& texture) { this->m_texture = texture; }

        Vector3f& getColor() { return this->m_color; }
        Vector3f getColor() const { return this->m_color; }
        void setColor(const Vector3f& color) { this->m_color = color; }

        float getSpecularIntensity() { return this->m_specularIntensity; }
        float getSpecularIntensity() const { return this->m_specularIntensity; }
        void setSpecularIntensity(const float specularIntensity) {
            this->m_specularIntensity = specularIntensity;
        }

        float getSpecularPower() { return this->m_specularPower; }
        float getSpecularPower() const { return this->m_specularPower; }
        void setSpecularPower(const float specularPower) {
            this->m_specularPower = specularPower;
        }

        virtual ~Material();


    protected:

    private:
        Texture m_texture;
        Vector3f m_color;
        float m_specularIntensity;
        float m_specularPower;
};

}
#endif // MATERIAL_H
