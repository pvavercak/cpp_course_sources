#include <iostream>
#include <memory.h>
#include <vector>
class Test
{
private:
    static const int SIZE = 100;
    int *buf;
public:
    Test()
    {
        std::cout << "constructor" << std::endl;
        buf = new int[SIZE]{};
    }

    Test(int i)
    {
        std::cout << "parametrized constructor" << std::endl;
        buf = new int[SIZE]{};

        for(int j = 0; j < SIZE; ++j)
        {
            buf[j] = i;
        }
    }

    Test(const Test &other)
    {
        std::cout << "copy constructor" << std::endl;
        buf = new int[SIZE]{};
        memcpy(buf, other.buf, SIZE*sizeof(int));
    }

    ~Test()
    {
        std::cout << "destructor" << std::endl;
        delete [] buf;
    }

    Test operator=(const Test &other)
    {
        std::cout << "assignment" << std::endl;
        buf = new int[SIZE]{};
        memcpy(buf, other.buf, SIZE*sizeof(int));
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &cls);
};

std::ostream &operator<<(std::ostream &out, const Test &cls)
{
    out << "hello from << operator";
    return out;
}

Test getTest()
{
    return Test();
}

void check(const Test &val)
{
    std::cout << "lValue function" << std::endl;
}

void check(Test &&val)
{
    std::cout << "rValue function" << std::endl;
}

int main()
{
    Test test1 = getTest();

    std::cout << test1 << std::endl;

    std::vector<Test> vec;
    vec.push_back(Test());

    Test &rTest = test1;

    const Test &rTest2 = getTest();
    Test test3(Test(3));

    int value1 = 7;

    int *pValue = &value1;

    Test *pTest = &test1;

    int *value2 = &++value1;
    // int *value5 = &value1++;

    std::cout << *value2 << std::endl;

    check(test1);
    check(getTest());



    return 0;
}