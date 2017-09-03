#ifndef VERTEX_H
#define VERTEX_H

#define VERTEX_SIZE 3
#include "vector3f.h"

namespace ogle {
class Vertex
{
    public:
        Vertex();
        Vertex(Vector3f& pos);
        Vertex(const Vertex& other);

        Vector3f getPos() { return this->m_position; }
        Vector3f getPos() const { return this->m_position; }
        void setPos(Vector3f& pos) {
            this->m_position.setX(pos.getX());
            this->m_position.setY(pos.getY());
            this->m_position.setZ(pos.getZ());
        }

        virtual ~Vertex();

    protected:

    private:
        void operator=(const Vertex& other);

        Vector3f m_position;
};
}
#endif // VERTEX_H
