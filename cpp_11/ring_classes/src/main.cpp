#include <iostream>

#include "ring.h"

int main()
{

    ring<std::string> myring(3);
    myring.add("one");
    myring.add("two");
    myring.add("three");

    for(ring<std::string>::iterator it = myring.begin(); it != myring.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    std::cout << std::endl;

    for(auto r : myring)
    {
        std::cout << r << std::endl;
    }

    return EXIT_SUCCESS;
}