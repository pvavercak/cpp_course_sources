#include <iostream>

#include <functional>

int add(int a, int b, int c)
{
    std::cout << a << ", " << b << ", " << c << std::endl;
    return a+b+c;
}

int main()
{

    auto calc = std::bind(add, 5, 5, 5);

    std::cout << calc() << std::endl;

    auto calc2 = std::bind(add, std::placeholders::_3, std::placeholders::_1, std::placeholders::_2);
    std::cout << calc2(6,7,3) << std::endl;
    return 0;
}