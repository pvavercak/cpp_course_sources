#ifndef COMPLEX_H
#define COMPLEX_H
#include <ostream>
class Complex
{
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(const Complex &other);
    Complex(double real, double imaginary);

    const Complex &operator=(const Complex &other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    bool operator==(const Complex &other) const;
    bool operator!=(const Complex &other) const;
    void operator+=(double d);
    Complex operator*() const;
};

// << left bit shifting
std::ostream &operator<<(std::ostream &out, const Complex &complex);

// + operator
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c, double d);
Complex operator+(double d, const Complex &c);

#endif // COMPLEX_H