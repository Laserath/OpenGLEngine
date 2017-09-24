#include "basicshader.h"

#include "resource_loader.h"

namespace ogle {

BasicShader *BasicShader::INSTANCE;

BasicShader *BasicShader::getInstance() {
    if (INSTANCE == nullptr) {
        INSTANCE = new BasicShader();
    }
    return INSTANCE;
}

BasicShader::BasicShader()
{
    std::string vertexShader = *ResourceLoader::loadShader("shaders/basicVertex.vs");
    std::string fragmentShader = *ResourceLoader::loadShader("shaders/basicFragment.fs");

    addVertexShader(vertexShader);
    addFragmentShader(fragmentShader);

    compileShader();

    addUniform("trans");
    addUniform("color");
}

void BasicShader::updateUniforms(Matrix4f& worldMatrix, Matrix4f& projectedMatrix, Mesh& mesh) {
    setUniform("trans", projectedMatrix);
    setUniform("color", mesh.getMaterial().getColor());
}

BasicShader::~BasicShader()
{
    //TODO
}

}
