#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "point_light.h"
#include "vector3f.h"

namespace ogle {

class SpotLight
{
    public:
        SpotLight();
        SpotLight(PointLight& pointLight, Vector3f& direction, float cutoff);
        SpotLight(SpotLight& other);

        PointLight& getPointLight() { return this->m_pointLight; }
        PointLight getPointLight() const { return this->m_pointLight; }
        void setPointLight(const PointLight& pointLight) {
            this->m_pointLight = pointLight;
        }

        Vector3f& getDirection() { return this->m_direction; }
        Vector3f getDirection() const { return this->m_direction; }
        void setDirection(const Vector3f& direction) {
            this->m_direction = direction;
        }

        float getCutoff() { return this->m_cutoff; }
        float getCutoff() const { return this->m_cutoff; }
        void setCutoff(const float cutoff) { this->m_cutoff = cutoff; }

    private:
        PointLight m_pointLight;
        Vector3f m_direction;
        float m_cutoff;
};

}

#endif // SPOT_LIGHT_H
