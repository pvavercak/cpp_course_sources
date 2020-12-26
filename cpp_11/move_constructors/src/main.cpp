#include <iostream>
#include <memory.h>
#include <vector>
class Test
{
private:
    static const int SIZE = 100;
    int *buf{nullptr};
public:
    Test()
    {
        buf = new int[SIZE]{};
    }

    Test(int i)
    {
        buf = new int[SIZE]{};

        for(int j = 0; j < SIZE; ++j)
        {
            buf[j] = i;
        }
    }

    Test(const Test &other)
    {
        buf = new int[SIZE]{};
        memcpy(buf, other.buf, SIZE*sizeof(int));
    }

    Test(Test &&other)
    {
        std::cout << "Move constructor" << std::endl;
        buf = other.buf;
        other.buf = nullptr;
    }

    ~Test()
    {
        delete [] buf;
    }

    Test operator=(const Test &other)
    {
        buf = new int[SIZE]{};
        memcpy(buf, other.buf, SIZE*sizeof(int));
        return *this;
    }

    Test &operator=(Test &&other)
    {
        std::cout << "Move assignment" << std::endl;
        delete [] buf;
        buf = other.buf;
        other.buf = nullptr;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &cls);
};

std::ostream &operator<<(std::ostream &out, const Test &cls)
{
    out << "test";
    return out;
}

Test getTest()
{
    return Test();
}

int main()
{
    std::vector<Test> vec;
    vec.push_back(Test());

    Test test;
    test = Test();

    return 0;
}