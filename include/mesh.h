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
        void addVertices(std::vector<Vertex> vertices);
        void draw();
        virtual ~Mesh();

    protected:

    private:
        void operator=(const Mesh& other);

        enum VertexBuffers {
            POSITION_VB,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexBufferObject[NUM_BUFFERS];
        uint64_t m_size;
};
}
#endif // MESH_H
