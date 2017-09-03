#include "mesh.h"

#include <GL/glew.h>

namespace ogle {
Mesh::Mesh()
{
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    glGenBuffers(NUM_BUFFERS, m_vertexBufferObject);
    //glGenBuffers(1, &m_indexBufferObject);
    glBindVertexArray(0);
    m_size = 0;
}

Mesh::Mesh(const Mesh& other)
{
    m_vertexArrayObject = other.m_vertexArrayObject;
    m_vertexBufferObject[POSITION_VB] = other.m_vertexBufferObject[POSITION_VB];
    m_vertexBufferObject[INDEX_VB] = other.m_vertexBufferObject[INDEX_VB];
    m_size = other.m_size;
    //m_indices = other.m_indices;
}

void Mesh::operator=(const Mesh& other) {
    m_vertexArrayObject = other.m_vertexArrayObject;
    m_vertexBufferObject[POSITION_VB] = other.m_vertexBufferObject[POSITION_VB];
    m_vertexBufferObject[INDEX_VB] = other.m_vertexBufferObject[INDEX_VB];
    m_size = other.m_size;
    //m_indices = other.m_indices;
}


void Mesh::addVertices(std::vector<Vertex> vertices, std::vector<GLuint> indices) {
    m_size = indices.size();
    std::vector<glm::vec3> data;
    for (Vertex vertex : vertices) {
        data.push_back(*vertex.getPos().asGLMVec());
    }

    glBindVertexArray(m_vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &data[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(data[0]), 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBufferObject[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    //dtor
}

}
