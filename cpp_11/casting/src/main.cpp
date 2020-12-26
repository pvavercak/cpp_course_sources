#include <iostream>

class Parent
{
public:
    void speak() const
    {
        std::cout << "Parent!" << std::endl;
    }
    
};

class Brother : public Parent
{
public:
    void speak() const
    {
        std::cout << "Brother!" << std::endl;
    }
};

class Sister : public Parent
{

};

int main()
{

    Brother brother;
    Sister sister;

    Parent *pb = &brother;

    pb->speak();

    Parent rB = brother;
    rB.speak();

    return EXIT_SUCCESS;
}