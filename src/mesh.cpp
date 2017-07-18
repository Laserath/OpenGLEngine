#include "mesh.h"

#include <GL/glew.h>

namespace ogle {
Mesh::Mesh()
{
    glGenBuffers(1, &vbo);
    size = 0;
}

Mesh::Mesh(const Mesh& other)
{
    //copy ctor
}

void Mesh::addVertices(std::vector<Vertex> vertices) {
    size = vertices.size();
    std::vector<glm::vec3> data;
    for (Vertex vertex : vertices) {
        data.push_back(*vertex.getPos().asGLMVec());
    }
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size * VERTEX_SIZE, &data, GL_STATIC_DRAW);
}

void Mesh::draw() {
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, size);

    //glDisableVertexAttribArray(0);
}

Mesh::~Mesh()
{
    //dtor
}

}
