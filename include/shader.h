#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <unordered_map>
#include "vector3f.h"
#include "matrix4f.h"
#include "mesh.h"

namespace ogle {
class Shader
{

    public:
        Shader();
        Shader(const Shader& other);
        Shader& operator=(const Shader& other);

        void addVertexShader(const std::string& shaderCode) { addShader(shaderCode, GL_VERTEX_SHADER); }
        void addFragmentShader(const std::string& shaderCode) { addShader(shaderCode, GL_FRAGMENT_SHADER); }
        void addGeometryShader(const std::string& shaderCode) { addShader(shaderCode, GL_GEOMETRY_SHADER); }

        void addUniform(const std::string& uniform);
        void setUniformi(const std::string& uniformName, const int value);
        void setUniformf(const std::string& uniformName, const float value);
        void setUniform(const std::string& uniformName, const Vector3f value);
        void setUniform(const std::string& uniformName, const Matrix4f value);

        void updateUniforms(Matrix4f& worldMatrix, Matrix4f& projectedMatrix, Mesh& mesh);

        void compileShader();
        void bind() {
            glUseProgram(m_program);
        }

        virtual ~Shader();

    protected:

    private:
        void addShader(const std::string& shaderCode, GLenum shaderType);

        GLuint m_program;
        // hold these for cleanup

        enum SHADERS {
            VERTEX_SHADER,
            FRAGMENT_SHADER,
            GEOMETRY_SHADER,
            NUM_SHADERS
        };

        GLuint m_shaders[SHADERS::NUM_SHADERS];
        std::unordered_map<std::string, GLuint> m_uniforms;
};
}
#endif // SHADER_H
