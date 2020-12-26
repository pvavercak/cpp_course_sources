#include <iostream>
#include <typeinfo>

class MyTestClass
{
private:
    int a;
    int b;
    int c;
public:
    MyTestClass() :
        a(1), b(2), c(3)
    {

    }
};

auto myfoo2(const std::string &value) -> std::string
{
    return value;
}

template<class T>
auto myfoo(T value) -> decltype(value)
{
    return value;
}

int main()
{

    std::string value;

    std::cout << typeid(value).name() << std::endl;

    decltype(value) name = "Bob";

    std::cout << typeid(name).name() << std::endl;

    MyTestClass mtc;

    std::cout <<typeid(mtc).name() << std::endl;


    std::cout << myfoo("string") << " - " << typeid(myfoo("string")).name() << std::endl;
    std::cout << myfoo(152525) << " - " << typeid(myfoo(152525)).name() << std::endl;
    std::cout << myfoo2("string") << " - " << typeid(myfoo2("string")).name() << std::endl;

    return EXIT_SUCCESS;
}