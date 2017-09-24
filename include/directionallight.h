#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "baselight.h"
#include "vector3f.h"

namespace ogle {
class DirectionalLight
{
    public:
        DirectionalLight();
        DirectionalLight(BaseLight& base, Vector3f& direction);
        DirectionalLight(const DirectionalLight& other);
        DirectionalLight& operator=(const DirectionalLight& other);

        BaseLight& getBase() { return this->m_base; }
        BaseLight getBase() const { return this->m_base; }
        void setBase(BaseLight& base) { this->m_base = base; }

        Vector3f& getDirection() { return this->m_direction; }
        Vector3f getDirection() const { return this->m_direction; }
        void setDirection(Vector3f& direction) { this->m_direction = direction; }

        virtual ~DirectionalLight();

    protected:

    private:
        BaseLight m_base;
        Vector3f m_direction;

};
}

#endif // DIRECTIONALLIGHT_H
