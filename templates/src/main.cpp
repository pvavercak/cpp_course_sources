#include <iostream>

template<class T>
class Test
{
private:
    T obj;

public:
    Test(T obj)
    {
        this->obj = obj;
    }

    void print() const
    {
        std::cout << obj << std::endl;
    }
};

template<class T>
void print(T arg)
{
    std::cout << "Template function: " << arg << std::endl;
}

void print(int arg)
{
    std::cout << "Non-template function: " << arg << std::endl;
}

template<class T>
void show()
{
    std::cout << T() << std::endl;
}

int main()
{
    Test<std::string> test1("Hello");

    test1.print();

    print<std::string>("Hello");
    print<int>(5);

    print("Hi");

    print(8);
    print<>(10);

    show<int>();

    return EXIT_SUCCESS;
}