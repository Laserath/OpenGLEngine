#include "shader.h"

#include <iostream>
#include <vector>

namespace ogle {
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
        //std::cout << "adding fragment shader" << std::endl;
        shaderHandle = &m_shaders[SHADERS::FRAGMENT_SHADER];
        break;
    case GL_GEOMETRY_SHADER:
        //std::cout << "adding geo shader" << std::endl;
        shaderHandle = &m_shaders[SHADERS::GEOMETRY_SHADER];
        break;
    case GL_VERTEX_SHADER:
        //std::cout << "adding vertex shader" << std::endl;
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
    glGetShaderiv(*shaderHandle, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(*shaderHandle, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(*shaderHandle, maxLength, &maxLength, &errorLog[0]);

        std::cerr << "Failed to compile shader(" << shaderType << "): " << &errorLog[0] << std::endl;
        exit(1);
    }
    glAttachShader(m_program, *shaderHandle);
}

void Shader::addUniform(const std::string& uniform) {
    int uniformLocation = glGetUniformLocation(m_program, uniform.c_str());
    if (uniformLocation == 0xFFFFFFFF) {
        std::cout << "Error: Unable to find unform " << uniform << std::endl;
        exit(1);
    }

    m_uniforms[uniform] = uniformLocation;

}

void Shader::setUniformi(const std::string& uniformName, int value) {
    glUniform1i(m_uniforms[uniformName], value);
}

void Shader::setUniformf(const std::string& uniformName, float value) {
    glUniform1f(m_uniforms[uniformName], value);
}

void Shader::setUniform(const std::string& uniformName, Vector3f value) {
    glUniform3f(m_uniforms[uniformName], value.getX(), value.getY(), value.getZ());
}

void Shader::setUniform(const std::string& uniformName, Matrix4f value) {
    glUniformMatrix4fv(m_uniforms[uniformName], 1, GL_TRUE, value.getMatrix());
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

}

