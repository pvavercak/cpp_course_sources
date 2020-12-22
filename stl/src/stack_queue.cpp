#include <iostream>
#include <stack>
#include <queue>

class Test
{
private:
    int id;
    std::string name;

public:
    Test(): 
        id(0), name("")
    {
        ;
    }

    Test(int id, std::string name):
        id(id),
        name(name)
    {
        ;
    }

    void print() const
    {
        std::cout << id << ": " << name << std::flush;
    }

    bool operator<(const Test &other)
    {
        return name < other.name;
    }
};

void stack_exercise()
{
    std::stack<Test> testStack;
    testStack.push(Test(5, "John"));
    testStack.push(Test(3, "Marc"));
    testStack.push(Test(1, "Patrik"));

    while(testStack.size() > 0)
    {
        Test &t = testStack.top();
        t.print();
        std::cout << std::endl;
        testStack.pop();
    }
}


void queue_exercise()
{
    std::queue<std::string> testQueue;

    testQueue.push("Marc");
    testQueue.push("Bill");
    testQueue.push("Eric");
    testQueue.push("Sophie");

    while(testQueue.size() > 0)
    {
        std::string &q = testQueue.front();
        std::cout << q << std::endl;

        testQueue.pop();
    }
}

int main()
{
    stack_exercise();
    queue_exercise();
    
    return EXIT_SUCCESS;
}