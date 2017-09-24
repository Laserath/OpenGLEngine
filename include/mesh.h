#ifndef MESH_H
#define MESH_H

#include <vector>
#include "vertex.h"
#include "texture.h"
#include "material.h"
#include <GL/glew.h>

namespace ogle {
class Mesh
{
    public:
        Mesh();
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);
        Material& getMaterial() { return this->m_material; }
        Material getMaterial() const { return this->m_material; }
        void addVertices(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
        void draw();
        virtual ~Mesh();

    protected:

    private:

        enum VertexBuffers {
            POSITION_VB,
            TEXCOORD_VB,
            NORMAL_VB,
            INDEX_VB,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexBufferObject[NUM_BUFFERS];
        //std::vector<GLuint> m_indices;
        Material m_material;
        uint64_t m_size;
};
}
#endif // MESH_H
