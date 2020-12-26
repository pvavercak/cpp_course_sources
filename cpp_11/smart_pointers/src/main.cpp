#include <iostream>
#include <memory>

class Test
{
public:
    Test()
    {
        std::cout << "created" << std::endl;
    }

    void greet()
    {
        std::cout << "hello" << std::endl;
    }

    ~Test()
    {
        std::cout << "destroyed" << std::endl;
    }
};

int main()
{
    std::shared_ptr<Test> spTest1 = std::make_shared<Test>();

    {
        std::shared_ptr<Test> spTest2 = std::make_shared<Test>();
        spTest1.reset();
    }

    std::cout << "end" << std::endl;
    return 0;
}