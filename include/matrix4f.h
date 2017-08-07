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
        std::shared_ptr<Matrix4f> multiply(const Matrix4f& r);

        std::vector<std::vector<float>> getMatrix() { return m_matrix; }
        std::vector<std::vector<float>> getMatrix() const { return m_matrix; }
        void setMatrix(std::vector<std::vector<float>> val) { m_matrix = val; }

        float getItem(const uint8_t x, const uint8_t y) const;
        float getItem(const uint8_t x, const uint8_t y);
        void setItem(const uint8_t x, const uint8_t y, const float val);

        std::shared_ptr<std::vector<float>> getItemsAsArray();

        virtual ~Matrix4f();

    protected:

    private:
        void operator=(const Matrix4f& other) { }

        std::vector<std::vector<float>> m_matrix;
};

std::ostream& operator<<(std::ostream& os, const Matrix4f& matrix4f);

}
#endif // MATRIX4F_H
