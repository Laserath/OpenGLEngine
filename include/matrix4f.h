#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>

#define MATRIX4F_SIZE 16 // 4 * 4 = matrix dimensions

namespace ogle {
class Matrix4f: public std::enable_shared_from_this<Matrix4f> {
    public:
        Matrix4f();
        Matrix4f(const Matrix4f& other);
        std::shared_ptr<Matrix4f> initIdentity();
        std::shared_ptr<Matrix4f> initTranslation(const float x, const float y, const float z);
        std::shared_ptr<Matrix4f> initRotation(const float x, const float y, const float z);
        std::shared_ptr<Matrix4f> initScale(const float x, const float y, const float z);
        std::shared_ptr<Matrix4f> initProjection(float fov, float width, float height, float zNear, float zFar);
        std::shared_ptr<Matrix4f> multiply(const Matrix4f& r);

        float* getMatrix() { return m_matrix; }
        const float* getMatrix() const { return m_matrix; }
        void setMatrix(const float val[MATRIX4F_SIZE]) {
            for (int i = 0; i < MATRIX4F_SIZE; i++) {
                this->m_matrix[i] = val[i];
            }
        }

        float getItem(const uint8_t x, const uint8_t y) const;
        float getItem(const uint8_t x, const uint8_t y);
        void setItem(const uint8_t x, const uint8_t y, const float val);

        virtual ~Matrix4f();

    protected:

    private:
        void operator=(const Matrix4f& other) { }

        float m_matrix[MATRIX4F_SIZE];
};

std::ostream& operator<<(std::ostream& os, const Matrix4f& matrix4f);

}
#endif // MATRIX4F_H
