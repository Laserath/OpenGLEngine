#include "matrix4f.h"

#include <cmath>

#define RADIAN_CONVERSION M_PI / 180.0

namespace ogle {
Matrix4f::Matrix4f() : m_matrix{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
{ }

Matrix4f::Matrix4f(const Matrix4f& other)
{
    this->setMatrix(other.getMatrix());
}

std::shared_ptr<Matrix4f> Matrix4f::initIdentity() {
    float identityMatrix[MATRIX4F_SIZE] =
    { 1,0,0,0,
      0,1,0,0,
      0,0,1,0,
      0,0,0,1 };
    this->setMatrix(identityMatrix);
    return this->shared_from_this();
}

std::shared_ptr<Matrix4f> Matrix4f::initTranslation(const float x, const float y, const float z) {
    float translationMatrix[MATRIX4F_SIZE] =
    { 1,0,0,x,
      0,1,0,y,
      0,0,1,z,
      0,0,0,1 };
    this->setMatrix(translationMatrix);
    return this->shared_from_this();
}

std::shared_ptr<Matrix4f> Matrix4f::initRotation(const float x, const float y, const float z) {

    Matrix4f rx, ry, rz;

    float radX, radY, radZ;
    radX = x * RADIAN_CONVERSION;
    radY = y * RADIAN_CONVERSION;
    radZ = z * RADIAN_CONVERSION;

    float rotationMatrixZ[MATRIX4F_SIZE] =
    { (float)cos(radZ) ,(float)-(sin(radZ)) ,0 ,0,
      (float)sin(radZ) ,  (float)cos(radZ)  ,0 ,0,
      0         ,0            ,1 ,0,
      0         ,0            ,0 ,1 };

    float rotationMatrixX[MATRIX4F_SIZE] =
    { 1, 0        ,0           , 0,
      0, (float)cos(radX),(float)-(sin(radX)), 0,
      0, (float)sin(radX),  (float)cos(radX) , 0,
      0, 0        ,0           , 1 };

    float rotationMatrixY[MATRIX4F_SIZE] =
    { (float)cos(radY), 0, (float)-(sin(radY)), 0,
      0        , 1, 0           , 0,
      (float)sin(radY), 0, (float)cos(radY)   , 0,
      0        , 0, 0           , 1 };

    rx.setMatrix(rotationMatrixX);
    ry.setMatrix(rotationMatrixY);
    rz.setMatrix(rotationMatrixZ);

    Matrix4f finalRotation = *(rz.multiply(*(ry.multiply(rx))));

    this->setMatrix(finalRotation.getMatrix());
    return this->shared_from_this();
}

std::shared_ptr<Matrix4f> Matrix4f::initScale(const float x, const float y, const float z) {
    float scaleMatrix[MATRIX4F_SIZE] =
    { x,0,0,0,
      0,y,0,0,
      0,0,z,0,
      0,0,0,1 };
    this->setMatrix(scaleMatrix);
    return this->shared_from_this();
}

std::shared_ptr<Matrix4f> Matrix4f::initProjection(float fov, float width, float height, float zNear, float zFar) {
    float tanHalfFOV = tan((fov / 2) * RADIAN_CONVERSION);
    float ar = width / height;
    float zRange = zNear - zFar;

    float identityMatrix[MATRIX4F_SIZE] =
    { 1.0 / (tanHalfFOV * ar),0,                      0,                        0,
      0,                      1.0 / (tanHalfFOV),     0,                        0,
      0,                      0,                      (-zNear - zFar) / zRange, 2 * zFar * zNear / zRange,
      0,                      0,                      1,                        0 };
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

float Matrix4f::getItem(const uint8_t x, const uint8_t y) const {
    return this->getMatrix()[x*4+y];
}

float Matrix4f::getItem(const uint8_t x, const uint8_t y) {
    return this->getMatrix()[x*4+y];
}

void Matrix4f::setItem(const uint8_t x, const uint8_t y, const float val) {
    this->getMatrix()[x*4+y] = val;
}

Matrix4f::~Matrix4f()
{

}

std::ostream& operator<<(std::ostream& os, const Matrix4f& matrix4f) {
    os << "[";
    for (int8_t i = 0; i < 4; i++) {
        os << "[ ";
        for (int8_t j = 0; j < 4; j++) {
            os << matrix4f.getItem(i, j) << " ";
        }
        os << "]";
    }
    os << "]";
    return os;
}
}
