#ifndef MESH_H
#define MESH_H

#include <vector>
#include "vertex.h"
#include <GL/glew.h>

namespace ogle {
class Mesh
{
    public:
        Mesh();
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);
        void addVertices(std::vector<Vertex> vertices, std::vector<GLuint> indices);
        void draw();
        virtual ~Mesh();

    protected:

    private:

        enum VertexBuffers {
            POSITION_VB,
            INDEX_VB,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexBufferObject[NUM_BUFFERS];
        //std::vector<GLuint> m_indices;
        uint64_t m_size;
};
}
#endif // MESH_H
