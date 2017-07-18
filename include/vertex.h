#ifndef VERTEX_H
#define VERTEX_H

#define VERTEX_SIZE 3
#include "vector3f.h"

namespace ogle {
class Vertex
{
    public:
        Vertex(Vector3f& pos);
        Vertex(const Vertex& other);

        Vector3f getPos() { return this->m_position; }
        Vector3f getPos() const { return this->m_position; }
        void setPos(Vector3f& pos) {
            this->m_position = pos;
        }

        virtual ~Vertex();

    protected:

    private:
        void operator=(const Vertex& other);

        Vector3f m_position;
};
}
#endif // VERTEX_H
