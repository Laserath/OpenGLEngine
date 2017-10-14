#ifndef VERTEX_H
#define VERTEX_H

#define VERTEX_SIZE 5
#include "vector3f.h"
#include "vector2f.h"

namespace ogle {
class Vertex
{
    public:
        Vertex();
        Vertex(Vector3f& pos, Vector2f& texCoords, Vector3f& normals);
        Vertex(const Vertex& other);

        Vector3f& getPos() { return this->m_position; }
        Vector3f getPos() const { return this->m_position; }
        void setPos(const Vector3f& pos) {
            this->m_position.setX(pos.getX());
            this->m_position.setY(pos.getY());
            this->m_position.setZ(pos.getZ());
        }

        Vector2f& getTexCoords() { return this->m_texCoords; }
        Vector2f getTexCoords() const { return this->m_texCoords; }
        void setTexCoords(const Vector2f& texCoords) {
            this->m_texCoords.setX(texCoords.getX());
            this->m_texCoords.setY(texCoords.getY());
        }

        Vector3f& getNormals() { return this->m_normals; }
        Vector3f getNormals() const { return this->m_normals; }
        void setNormals(const Vector3f& normals) {
            this->m_normals.setX(normals.getX());
            this->m_normals.setY(normals.getY());
            this->m_normals.setZ(normals.getZ());
        }

        virtual ~Vertex();

    protected:

    private:
        void operator=(const Vertex& other);

        Vector3f m_position;
        Vector2f m_texCoords;
        Vector3f m_normals;
};
}
#endif // VERTEX_H
