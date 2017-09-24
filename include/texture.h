#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>

namespace ogle {

enum class TEXTURE_TYPE {
    DIFFUSE,
    SPECULAR,
    UNKNOWN
};

class Texture
{
    public:

        Texture();
        Texture(GLuint id, TEXTURE_TYPE type, std::string& path);
        Texture(const Texture& other);
        Texture& operator=(const Texture& other);

        GLuint getID() { return this->m_id; }
        GLuint getID() const { return this->m_id; }

        TEXTURE_TYPE getType() { return this->m_type; }
        TEXTURE_TYPE getType() const { return this->m_type; }

        std::string getPath() { return this->m_path; }
        std::string getPath() const { return this->m_path; }

        void bind();
        void unbind();

        virtual ~Texture();

    protected:

    private:
        GLuint m_id;
        TEXTURE_TYPE m_type;
        std::string m_path;
};
}

#endif // TEXTURE_H
