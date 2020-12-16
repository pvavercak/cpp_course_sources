#include <iostream>
#include <string>
#include <exception>
/**
 * Exceptions Basics 1st video
 */
void exception_function(bool param) {

    if(param) {
        throw 8;
    }
    else {
        throw "Something went wrong.";
    }
}

void uses_exception_function() {
    exception_function(false);
}

// ############################


/**
 * Exceptions Basics 2nd video
 */

class CanGoWrong {
public:
    CanGoWrong() {
        char *arr = new char[999999999999];
        delete [] arr;
    }
};


// ############################

class MyException: public std::exception {
public:
    virtual const char* what() const throw() {
        return "Customized exception message";
    }
};

class Test {
public:
    void goesWrong() {
        throw MyException();
    }
};

int main() {

    // 1st video
    // try {
    //     // exception_function(false);
    //     uses_exception_function();
    // }
    // catch (int e) {
    //     std::cout << "Threw INT: " << e << std::endl;
    // }
    // catch (char const* e) {
    //     std::cout << "Threw CHARARRAY: " << e << std::endl;
    // }
    // catch (std::string e) {
    //     std::cout << "Threw STRING: " << e << std::endl;
    // }

    // 2nd video
    // try {
    //     CanGoWrong wrong;
    // }
    // catch (std::bad_alloc &ba){
    //     std::cout<< "Caught " << ba.what() << std::endl;
    // }

    // 3rd video
    Test test;

    try {
        test.goesWrong();
    }
    catch (MyException &e) {
        std::cout << e.what() << std::endl;
    }
    

    return EXIT_SUCCESS;
}