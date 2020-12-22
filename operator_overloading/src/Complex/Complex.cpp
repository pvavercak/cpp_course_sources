#include "Complex.h"

std::ostream &operator<<(std::ostream &out, const Complex &complex)
{
    out << "(" << complex.getReal() << ", " << complex.getImaginary() << ")";
    return out;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(
        c1.getReal() + c2.getReal(),
        c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex &c, double d)
{
    return Complex(c.getReal() + d, c.getImaginary());
}

Complex operator+(double d, const Complex &c)
{
    return Complex(c.getReal() +d, c.getImaginary());
}

Complex::Complex():
    real(0),
    imaginary(0)
{

}

Complex::Complex(const Complex &other)
{
    real = other.real;
    imaginary = other.imaginary;
}

Complex::Complex(double real, double imaginary) :
    real(real), imaginary(imaginary)
{

}

const Complex &Complex::operator=(const Complex &other)
{
    real = other.real;
    imaginary = other.imaginary;
    return *this;
}

bool Complex::operator==(const Complex &other) const
{
    return (real == other.real)
        && (imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex &other) const
{
    return !(*this == other);
}

void Complex::operator+=(double d)
{
    real += d;
}

Complex Complex::operator*() const
{
    return Complex(real, -imaginary);
}
