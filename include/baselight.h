#ifndef BASELIGHT_H
#define BASELIGHT_H

#include "vector3f.h"

namespace ogle {
class BaseLight
{
    public:
        BaseLight();
        BaseLight(Vector3f& color, float intensity);
        BaseLight(const BaseLight& other);
        BaseLight& operator=(const BaseLight& other);

        Vector3f& getColor() { return this->m_color; }
        Vector3f getColor() const { return this->m_color; }
        void setColor(const Vector3f& color) { this->m_color = color; }

        float getIntensity() { return this->m_intensity; }
        float getIntensity() const { return this->m_intensity; }
        void setIntensity(const float intensity) { this->m_intensity = intensity; }

        virtual ~BaseLight();


    protected:

    private:
        Vector3f m_color;
        float m_intensity;
};
}

#endif // BASELIGHT_H
