#include "mesh.h"

#include <GL/glew.h>

namespace ogle {
Mesh::Mesh()
{
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    glGenBuffers(NUM_BUFFERS, m_vertexBufferObject);

    glBindVertexArray(0);
    m_size = 0;
}

Mesh::Mesh(const Mesh& other)
{
    //copy ctor
}

void Mesh::addVertices(std::vector<Vertex> vertices) {
    m_size = vertices.size();
    std::vector<glm::vec3> data;
    for (Vertex vertex : vertices) {
        data.push_back(*vertex.getPos().asGLMVec());
    }

    glBindVertexArray(m_vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(data[0]), &data[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[POSITION_VB]);

    glDrawArrays(GL_TRIANGLES, 0, m_size);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    //dtor
}

}
