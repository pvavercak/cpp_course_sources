#include <iostream>
#include <vector>

void test()
{
    std::cout << "Hello" << std::endl;
}

void test2(int value)
{
    std::cout << value << std::endl;
}

int* test3(std::string value)
{
    std::cout <<"Hello from test3:\n" << value << std::endl;
    int f = 8;

    return &f;
}

bool myTestFunction(const std::string &test_string)
{
    return test_string == "two";
}

int my_count_if(std::vector<std::string> &collection, bool (*bool_function)(const std::string &test_string))
{
    int count = 0;

    for(const std::string &item : collection)
    {
        if(bool_function(item))
        {
            ++count;
        }
    }

    return count;
}

class Parent
{
private:
    int one;
public:
    Parent() : 
        one(0)
    {

    }

    Parent(const Parent &other)
    {
        one = other.one;
        std::cout << "Parent copy constructor running" << std::endl;
    }

    virtual void print() const {
        std::cout << "Parent : " << one << std::endl;
    }

    virtual ~Parent()
    {
        
    }
};

class Child : public Parent
{
private:
    int two;
public:
    Child() :
        two(0)
    {

    }

    Child(const Child &other)
    {
        two = other.two;
        std::cout << "Child copy constructor running" << std::endl;
    }

    void print() const
    {
        std::cout <<  "Child : " << two << std::endl;
    }
};

class Animal
{
public:
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Labrador : public Dog
{
public:
    virtual void run()
    {
        std::cout << "Labrador running!" << std::endl;
    }
};

int main()
{/*

    void (*pTest)() = test;
    pTest();

    void (*pTest2)(int) = test2;
    pTest2(5);

    int* (*pTest3)(std::string) = test3;
    int *invalidAddr = pTest3(">cave of programming<");

    std::vector<std::string> nums;

    nums.push_back("one");
    nums.push_back("two");
    nums.push_back("three");
    nums.push_back("two");
    nums.push_back("four");
    nums.push_back("six");
    nums.push_back("two");

    std::cout << "Number of twos in a vector: " << my_count_if(nums, myTestFunction) << std::endl;


    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();
*/
    Labrador labrador;

    Dog &dog = labrador;
    Animal &animal = labrador;

    labrador.speak();
    labrador.run();
    dog.run(); // dog does not have run() implemented
    animal.run(); // also animal does not have run() implemented
                //but they both refer to instance of Labrador

    return EXIT_SUCCESS;
}