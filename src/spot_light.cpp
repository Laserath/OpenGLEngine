#include "include/spot_light.h"

namespace ogle {
SpotLight::SpotLight()
{

}

SpotLight::SpotLight(PointLight& pointLight, Vector3f& direction, float cutoff) {
    this->m_cutoff = cutoff;
    this->m_pointLight = pointLight;
    this->m_direction = *direction.normalize();
}

SpotLight::SpotLight(SpotLight& other) {
    this->m_cutoff = other.getCutoff();
    this->m_direction = other.getDirection();
    this->m_pointLight = other.getPointLight();
}

}
