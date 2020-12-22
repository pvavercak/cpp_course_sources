#include <iostream>
#include "Complex/Complex.h"

class Test
{
private:
    int id;
    std::string name;
public:
    void print() const
    {
        std::cout << id << ": " << name << std::endl;
    }

    Test(const int id, const std::string &name) :
        id(id), name(name)
    {
        std::cout << ">>>> Copy constructor running <<<<" << std::endl;
    }

    Test(const Test &other)
    {
        std::cout << ">>>> Copy assignment running <<<<" << std::endl;
        id = other.id;
        name = other.name;
    }

    const Test &operator=(const Test &other)
    {
        std::cout << ">>>> Assignment operator running <<<<" << std::endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &test)
    {
        out << test.id << ": " << test.name;
        return out;
    }
};

void overloaded_assignment_operator()
{
    std::cout << "Using copy constructor:" << std::endl;
    Test t1 = Test(1, "Patrik");
    t1.print();

    std::cout << "Using copy assignment:" << std::endl;
    Test t2 = t1;
    t2.print();

    std::cout << "Using assignment operator:" << std::endl;
    t1 = t2;
    t1.print();

    std::cout << "Using both, copy constructor and assignment operator:" << std::endl;
    t2 = Test(5, "John");
    t2.print();
}

void left_bitshift_operator_overloading()
{
    Test t = Test(6, "Patrik");

    std::cout << "Output using overloaded operator <<:\n"<< t << std::endl;
}

void complex_class_testing()
{
    Complex c1(2, 3);
    std::cout << c1 << std::endl;
}

void overloaded_plus_testing()
{
    Complex c(2, 3);
    Complex c2(4, 1);

    Complex c3 = 7 + c + 1 + c2 + 4;

    std::cout << c3 << std::endl;
}

void comparison_operator_testing()
{
    Complex c1(5, 4);
    Complex c2(5, 4);

    std::cout << "Should be equal: " << (c1 == c2) << std::endl;

    c1 += 1;

    std::cout << "Shouldn't be equal: " << (c1 != c2) << std::endl;
}

void asterisk_overriding_test()
{
    Complex c(2, 5);

    std::cout << *c << std::endl;
}

int main()
{
    // overloaded_assignment_operator();

    // left_bitshift_operator_overloading();
    // complex_class_testing();
    // overloaded_plus_testing();

    // comparison_operator_testing();
    asterisk_overriding_test();
    return EXIT_SUCCESS;
}