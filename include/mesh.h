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

        GLuint vbo;
        uint64_t size;
};
}
#endif // MESH_H
