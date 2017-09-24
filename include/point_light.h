#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "baselight.h"
#include "attenuation.h"
#include "vector3f.h"

namespace ogle {
class PointLight
{
    public:
        PointLight();
        PointLight(BaseLight& base, Attenuation& atten, Vector3f& position);
        PointLight(const PointLight& other);
        PointLight& operator=(const PointLight& other);

        BaseLight& getBaseLight() { return this->m_base; }
        BaseLight getBaseLight() const { return this->m_base; }
        void setBaseLight(BaseLight& base) {
            this->m_base = base;
        }

        Vector3f& getPosition() { return this->m_position; }
        Vector3f getPosition() const { return this->m_position; }
        void setPosition(Vector3f& position) {
            this->m_position = position;
        }

        Attenuation& getAtten() { return this->m_atten; }
        Attenuation getAtten() const { return this->m_atten; }
        void setAtten(Attenuation& atten) {
            this->m_atten = atten;
        }

        virtual ~PointLight();


    protected:

    private:
        BaseLight m_base;
        Vector3f m_position;
        Attenuation m_atten;
};
}

#endif // POINT_LIGHT_H
