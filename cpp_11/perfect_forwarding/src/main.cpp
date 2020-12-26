#include <iostream>

class Test
{

};

template<typename T>
void call(T &&arg)
{
    check(arg);
}

void check(Test &test)
{
    std::cout << "lvalue" << std::endl;
}


void check(Test &&test)
{
    std::cout << "rvalue" << std::endl;
}

int main()
{
    Test t;

    check(std::forward<Test>(t));

    check(t);

    return EXIT_SUCCESS;
}