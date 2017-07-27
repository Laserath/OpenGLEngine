#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>

class Shader
{

    public:
        Shader();
        Shader(const Shader& other);

        void addVertexShader(const std::string& shaderCode) { addShader(shaderCode, GL_VERTEX_SHADER); }
        void addFragmentShader(const std::string& shaderCode) { addShader(shaderCode, GL_FRAGMENT_SHADER); }
        void addGeometryShader(const std::string& shaderCode) { addShader(shaderCode, GL_GEOMETRY_SHADER); }

        void compileShader();
        void bind() { glUseProgram(m_program); }

        virtual ~Shader();


    protected:

    private:
        void operator=(const Shader& other) {}
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
};

#endif // SHADER_H
