#include "vertex.h"

namespace ogle {

Vertex::Vertex(): m_position(0.0f, 0.0f, 0.0f), m_texCoords(0.0f, 0.0f), m_normals(0.0f, 0.0f, 0.0f) {
}

Vertex::Vertex(Vector3f& pos, Vector2f& texCoords, Vector3f& normals): m_position(0.0f, 0.0f, 0.0f), m_texCoords(0.0f, 0.0f), m_normals(0.0f, 0.0f, 0.0f)
{
    this->m_position = pos;
    this->m_texCoords = texCoords;
    this->m_normals = normals;
}

Vertex::Vertex(const Vertex& other): m_position(0.0f, 0.0f, 0.0f), m_texCoords(0.0f, 0.0f), m_normals(0.0f, 0.0f, 0.0f)
{
    m_position = other.getPos();
    m_texCoords = other.getTexCoords();
    m_normals = other.getNormals();
}

Vertex::~Vertex()
{
    //dtor
}

}
