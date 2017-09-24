#ifndef BASICSHADER_H
#define BASICSHADER_H

#include "shader.h"

namespace ogle {
class BasicShader: public Shader
{
    public:
        static BasicShader *getInstance();
        void updateUniforms(Matrix4f& worldMatrix, Matrix4f& projectedMatrix, Mesh& mesh);

        virtual ~BasicShader();
    protected:

    private:
        BasicShader();
        BasicShader(const BasicShader& other) {}
        BasicShader& operator=(const BasicShader& other) {}

        static BasicShader *INSTANCE;
};
}
#endif // BASICSHADER_H
