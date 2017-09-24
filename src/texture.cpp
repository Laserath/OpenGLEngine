#include "texture.h"

#include <GL/glew.h>

namespace ogle {
Texture::Texture() {
    this->m_id = 0;
    this->m_path = "";
    this->m_type = TEXTURE_TYPE::DIFFUSE;
}

Texture::Texture(GLuint id, TEXTURE_TYPE type, std::string& path)
{
    this->m_id = id;
    this->m_type = type;
    this->m_path = path;
}

Texture::Texture(const Texture& other)
{
    this->m_id = other.getID();
    this->m_path = other.getPath();
    this->m_type = other.getType();
}

Texture& Texture::operator=(const Texture& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->m_id = rhs.getID();
    this->m_path = rhs.getPath();
    this->m_type = rhs.getType();
    return *this;
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, this->getID());
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
    //dtor
}
}

