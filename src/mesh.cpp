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

Mesh::Mesh(const Mesh& other) {
    m_vertexArrayObject = other.m_vertexArrayObject;
    m_vertexBufferObject[POSITION_VB] = other.m_vertexBufferObject[POSITION_VB];
    m_vertexBufferObject[INDEX_VB] = other.m_vertexBufferObject[INDEX_VB];
    m_vertexBufferObject[TEXCOORD_VB] = other.m_vertexBufferObject[TEXCOORD_VB];
    m_vertexBufferObject[NORMAL_VB] = other.m_vertexBufferObject[NORMAL_VB];
    m_size = other.m_size;
    m_material = other.getMaterial();
}

void Mesh::operator=(const Mesh& other) {
    m_vertexArrayObject = other.m_vertexArrayObject;
    m_vertexBufferObject[POSITION_VB] = other.m_vertexBufferObject[POSITION_VB];
    m_vertexBufferObject[INDEX_VB] = other.m_vertexBufferObject[INDEX_VB];
    m_vertexBufferObject[TEXCOORD_VB] = other.m_vertexBufferObject[TEXCOORD_VB];
    m_vertexBufferObject[NORMAL_VB] = other.m_vertexBufferObject[NORMAL_VB];
    m_material = other.getMaterial();
    m_size = other.m_size;
}


void Mesh::addVertices(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures) {
    m_size = indices.size();
    std::vector<glm::vec3> posData;
    std::vector<glm::vec2> texData;
    std::vector<glm::vec3> normalData;
    for (Vertex vertex : vertices) {
        posData.push_back(*vertex.getPos().asGLMVec());
        texData.push_back(*vertex.getTexCoords().asGLMVec());
        normalData.push_back(*vertex.getNormals().asGLMVec());
    }
    for (Texture texture : textures) {
        if (texture.getType() == TEXTURE_TYPE::DIFFUSE) {
            m_material.setTexture(texture);
            break;
        }
    }

    glBindVertexArray(m_vertexArrayObject);

    // Position
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, posData.size() * sizeof(posData[0]), &posData[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(posData[0]), 0);

    // Texture Coordinates
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, texData.size() * sizeof(texData[0]), &texData[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(texData[0]), 0);

    // Normals
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, normalData.size() * sizeof(normalData[0]), &normalData[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(normalData[0]), 0);

    // Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBufferObject[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::draw() {
    glBindVertexArray(m_vertexArrayObject);

    getMaterial().getTexture().bind();
    glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    //dtor
}

}
