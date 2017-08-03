#include "matrix4f.h"

namespace ogle {
Matrix4f::Matrix4f()
{
    this->m_matrix = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
}

Matrix4f::Matrix4f(const Matrix4f& other)
{
    this->setMatrix(other.getMatrix());
}

std::shared_ptr<Matrix4f> Matrix4f::initIdentity() {
    std::vector<std::vector<float>> identityMatrix =
    { {1,0,0,0},
      {0,1,0,0},
      {0,0,1,0},
      {0,0,0,1} };
    this->setMatrix(identityMatrix);
    return this->shared_from_this();
}

std::shared_ptr<Matrix4f> Matrix4f::multiply(const Matrix4f& r) {
    std::shared_ptr<Matrix4f> newMat = std::make_shared<Matrix4f>();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newMat->setItem(i, j, this->getItem(i,0) * r.getItem(0, j) +
                                       this->getItem(i,1) * r.getItem(1, j) +
                                       this->getItem(i,2) * r.getItem(2, j) +
                                       this->getItem(i,3) * r.getItem(3, j));
        }
    }

    return newMat;
}

std::shared_ptr<float> Matrix4f::getItemsAsArray() {
    std::shared_ptr<float> arrayPtr(float[4][4], std::default_delete<float[][]>());
    for (int i = 0; i < 4; i++) {
        for (int j = 0; i < 4; j++) {
            arrayPtr[i][j] = m_matrix[i][j];
        }
    }
    return arrayPtr;
}

float Matrix4f::getItem(const uint8_t x, const uint8_t y) const {
    return this->getMatrix()[x][y];
}

float Matrix4f::getItem(const uint8_t x, const uint8_t y) {
    return this->getMatrix()[x][y];
}

void Matrix4f::setItem(const uint8_t x, const uint8_t y, const float val) {
    this->getMatrix()[x][y] = val;
}

Matrix4f::~Matrix4f()
{

}

std::ostream& operator<<(std::ostream& os, const Matrix4f& matrix4f) {
    os << "[";
    for (int8_t i = 0; i < 4; i++) {
        os << "[ ";
        for (int8_t j = 0; j < 4; j++) {
            os << matrix4f.getMatrix()[i][j] << " ";
        }
        os << "]";
    }
    os << "]";
    return os;
}
}
