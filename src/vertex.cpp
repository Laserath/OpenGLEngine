#include "vertex.h"

namespace ogle {

Vertex::Vertex(Vector3f& pos): m_position(0.0f, 0.0f, 0.0f)
{
    this->m_position = pos;
}

Vertex::Vertex(const Vertex& other): m_position(0.0f, 0.0f, 0.0f)
{
    m_position = other.getPos();
}

Vertex::~Vertex()
{
    //dtor
}

}
