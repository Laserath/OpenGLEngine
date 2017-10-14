#ifndef ATTENUATION_H
#define ATTENUATION_H

namespace ogle {

class Attenuation
{
    public:
        Attenuation();
        Attenuation(float constant, float linear, float exponent);
        Attenuation(const Attenuation& other);
        Attenuation& operator=(const Attenuation& other);

        float getConstant() { return this->m_constant; }
        float getConstant() const { return this->m_constant; }
        void setConstant(const float constant) { this->m_constant = constant; }

        float getLinear() { return this->m_linear; }
        float getLinear() const { return this->m_linear; }
        void setLinear(const float linear) { this->m_linear = linear; }

        float getExponent() { return this->m_exponent; }
        float getExponent() const { return this->m_exponent; }
        void setExponent(const float exponent) { this->m_exponent = exponent; }

        virtual ~Attenuation();

    protected:

    private:
        float m_constant;
        float m_linear;
        float m_exponent;
};

}
#endif // ATTENUATION_H
