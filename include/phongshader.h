#ifndef PHONGSHADER_H
#define PHONGSHADER_H

#include "shader.h"
#include "directionallight.h"
#include "vector3f.h"
#include "transform.h"
#include "point_light.h"
#include <string>

#define MAX_POINT_LIGHTS 4

namespace ogle {
class PhongShader: public Shader
{
    public:
        static PhongShader *getInstance();
        void updateUniforms(Matrix4f& worldMatrix, Matrix4f& projectedMatrix, Mesh& mesh, Transform& transform);

        Vector3f& getAmbientLight() { return this->m_ambientLight; }
        Vector3f getAmbientLight() const { return this->m_ambientLight; }
        void setAmbientLight(Vector3f& ambientLight) {
            this->m_ambientLight.setX(ambientLight.getX());
            this->m_ambientLight.setY(ambientLight.getY());
            this->m_ambientLight.setZ(ambientLight.getZ());
        }

        DirectionalLight& getDirectionalLight() { return this->m_directionalLight; }
        DirectionalLight getDirectionalLight() const { return this->m_directionalLight; }
        void setAmbientLight(DirectionalLight& directionalLight) {
            this->m_directionalLight = directionalLight;
        }

        void setUniform(const std::string& uniformName, const DirectionalLight& directionalLight);
        void setUniform(const std::string& uniformName, const PointLight& pointLight);
        void setUniform(const std::string& uniformName, const Attenuation& atten);
        void setUniform(const std::string& uniformName, const BaseLight& baseLight);

        virtual ~PhongShader();

        static void addPointLight(const PointLight& pointLight);

    protected:

    private:
        PhongShader();
        PhongShader(const PhongShader& other) {}
        PhongShader& operator=(const PhongShader& other) {}

        static PhongShader *INSTANCE;
        static PointLight pointLights[];
        static int numPointLights;
        Vector3f m_ambientLight;
        DirectionalLight m_directionalLight;
};
}
#endif // PHONGSHADER_H
