#include <iostream>
#include <initializer_list>

template<typename T>
class Test
{
public:
    Test(std::initializer_list<T> initlist)
    {
        for(auto s: initlist)
        {
            std::cout << s << std::endl;
        }
    }
};

int main()
{

    int *pInts = new int[3]{1, 2, 3};
    delete [] pInts;
    int *pSth{}; // == nullptr
    int *nums[5]{};

    Test<std::string> t{"one", "two", "three"};
    Test<int> t2{1, 2, 3};

    return EXIT_SUCCESS;
}