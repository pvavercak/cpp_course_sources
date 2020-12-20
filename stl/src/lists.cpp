#include <iostream>
#include <list>


int main()
{
    std::list<int> ints;

    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    std::list<int>::iterator it = ints.begin();
    it = ints.insert(it, 0);

    ++it;
    ints.insert(it, 100);

    std::list<int>::iterator eraseIt = ints.begin();
    ++eraseIt;
    eraseIt = ints.erase(eraseIt);


    it = ints.begin();
    while(it != ints.end())
    {
        if(1 == *it)
        {
            ints.insert(it, 100);
        }

        if(2 == *it)
        {
            it = ints.erase(it);
        } else {
            ++it;
        }
    }

    it = ints.begin();
    while(it != ints.end())
    {
        std::cout << *it << std::endl;

        ++it;
    }

    return EXIT_SUCCESS;
}