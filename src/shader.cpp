#include "shader.h"

#include <iostream>
#include <vector>

Shader::Shader()
{
    m_program = glCreateProgram();

    if (!m_program) {
        std::cerr << "Shader: Unable to get memory for program in constructor." << std::endl;
        exit(1);
    }

    m_shaders[SHADERS::VERTEX_SHADER] = 0;
    m_shaders[SHADERS::FRAGMENT_SHADER] = 0;
    m_shaders[SHADERS::GEOMETRY_SHADER] = 0;
}

Shader::Shader(const Shader& other)
{
    m_program = other.m_program;
    std::copy(std::begin(other.m_shaders), std::end(other.m_shaders), m_shaders);
}

void Shader::addShader(const std::string& shaderCode, GLenum shaderType) {
    GLuint *shaderHandle;
    switch(shaderType) {
    case GL_FRAGMENT_SHADER:
        shaderHandle = &m_shaders[SHADERS::FRAGMENT_SHADER];
        break;
    case GL_GEOMETRY_SHADER:
        shaderHandle = &m_shaders[SHADERS::GEOMETRY_SHADER];
        break;
    case GL_VERTEX_SHADER:
        shaderHandle = &m_shaders[SHADERS::VERTEX_SHADER];
        break;
    default:
        std::cerr << "Unknown shaderType when adding shader: " << shaderType << std::endl;
        exit(1);
    }
    *shaderHandle = glCreateShader(shaderType);
    const char* shaderSource = shaderCode.c_str();
    glShaderSource(*shaderHandle, 1, &shaderSource, NULL);
    glCompileShader(*shaderHandle);
    GLint isCompiled = 0;
    glGetShaderiv(*shaderHandle, shaderType, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(*shaderHandle, shaderType, &maxLength);
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(*shaderHandle, maxLength, &maxLength, &errorLog[0]);

        std::cerr << "Failed to compile shader(" << shaderType << "): " << &errorLog[0] << std::endl;
        exit(1);
    }
}

void Shader::compileShader() {
    GLint isLinked;

    glLinkProgram(m_program);

    glGetProgramiv(m_program, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE) {
        // link failed, get and print logs
        GLint maxLength;

        glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, (int *)&maxLength);
        std::vector<GLchar> message(maxLength);
        glGetProgramInfoLog(m_program, maxLength, &maxLength, &message[0]);

        std::cerr << "Program link failed: " << &message[0] << std::endl;
        exit(1);
    }

    glDetachShader(m_shaders[SHADERS::FRAGMENT_SHADER], GL_FRAGMENT_SHADER);
    glDetachShader(m_shaders[SHADERS::VERTEX_SHADER], GL_VERTEX_SHADER);
    glDetachShader(m_shaders[SHADERS::GEOMETRY_SHADER], GL_GEOMETRY_SHADER);

}

Shader::~Shader()
{
    if (m_shaders[SHADERS::VERTEX_SHADER] != 0) {
        glDeleteShader(m_shaders[SHADERS::VERTEX_SHADER]);
    }
    if (m_shaders[SHADERS::FRAGMENT_SHADER] != 0) {
        glDeleteShader(m_shaders[SHADERS::FRAGMENT_SHADER]);
    }
    if (m_shaders[SHADERS::GEOMETRY_SHADER] != 0) {
        glDeleteShader(m_shaders[SHADERS::GEOMETRY_SHADER]);
    }
    glDeleteProgram(m_program);
}



