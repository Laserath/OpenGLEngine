#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <memory>
#include "vector3f.h"
#include "matrix4f.h"

namespace ogle {
class Transform
{
    public:
        Transform();
        Transform(Transform& other);
        virtual ~Transform();

        std::shared_ptr<Matrix4f> getTransformation();
        std::shared_ptr<Matrix4f> getProjectedTransformation();

        Vector3f& getTranslation() { return m_translation; }
        void setTranslation(const Vector3f& value) { m_translation = value; }
        void setTranslation(const float x, const float y, const float z) {
            m_translation.setX(x);
            m_translation.setY(y);
            m_translation.setZ(z);
        }

        Vector3f& getRotation() { return m_rotation; }
        void setRotation(const Vector3f& value) { m_rotation = value; }
        void setRotation(const float x, const float y, const float z) {
            m_rotation.setX(x);
            m_rotation.setY(y);
            m_rotation.setZ(z);
        }

        Vector3f& getScale() { return m_scale; }
        void setScale(const Vector3f& value) { m_scale = value; }
        void setScale(const float x, const float y, const float z) {
            m_scale.setX(x);
            m_scale.setY(y);
            m_scale.setZ(z);
        }

        static void setProjection(float fov, float width, float height, float zNear, float zFar) {
            Transform::m_fov = fov;
            Transform::m_width = width;
            Transform::m_height = height;
            Transform::m_zNear = zNear;
            Transform::m_zFar = zFar;
        }

        Camera& getCamera() { return this->m_camera; }
        Camera getCamera() const { return this->m_camera; }
        void setCamera(Camera& camera) { this->m_camera = camera; }

    protected:

    private:
        Transform& operator=(const Transform& other) { }

        Vector3f m_translation;
        Vector3f m_rotation;
        Vector3f m_scale;
        Camera m_camera;

        static float m_zNear;
        static float m_zFar;
        static float m_width;
        static float m_height;
        static float m_fov;
};



}
#endif // TRANSFORM_H
