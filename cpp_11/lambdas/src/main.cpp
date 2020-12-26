#include <iostream>
#include <typeinfo>
#include <functional>
#include <algorithm>

void foo(void (*otherFoo)())
{
    otherFoo();
}


void pGreet(void (*greet)(std::string))
{
    greet("Hello from pGreet");
}

void runDivide(double (*divider)(double, double))
{
    double result = divider(10.0, 5.0);
    std::cout << result << std::endl;
}

class Test
{
private:
    int one{1};
    int two{2};
public:
    void run()
    {
        std::cout <<"We are in Test::run()" << std::endl;
        int three{3};
        int four{4};

        auto pLambda = [&](){
            std::cout << "Instance one: " << one  << " addr " << &one << std::endl;
            std::cout << "Instance two: " << two << " addr " << &two << std::endl;
            std::cout << "Local three: " << three << " addr " << &three << std::endl;
            std::cout << "Local four: " << four << " addr " << &four << std::endl;
        };

        std::cout << &three << std::endl;
        std::cout << &four << std::endl;

        pLambda();
    }

    ~Test()
    {
        std::cout << "Test destroyed" << std::endl;
    }
};

class Check
{
public:
    bool operator()(const std::string &str)
    {
        return str.size() == 3;
    }
};

bool check(const std::string &str)
{
    return str.size() == 3;
}

void run(std::function<bool(const std::string&)> pCheck, const std::string &test)
{
    std::cout << pCheck(test) << std::endl;
}

class Elide
{
public:
    Elide()
    {
        std::cout << "constructor" << std::endl;
    }

    Elide(const Elide &other)
    {
        std::cout << "copy constructor" << std::endl;
    }

    ~Elide()
    {
        std::cout << "destructor" << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, const Elide &cls);
};

std::ostream &operator<<(std::ostream &out, const Elide &cls)
{
    out << "hello from << operator";
    return out;
}

Elide getClass()
{
    return Elide();
}

int main()
{
    auto lamb = [](){ std::cout << "Hello from lambda" << std::endl;};
    foo(lamb);
    foo([](){ std::cout << "Hello from lambda again"<< std::endl;});

    auto greetLambda = [](std::string greeting) {
        std::cout << greeting << std::endl;
    };

    pGreet(greetLambda);

    auto divideLambda = [](double a, double b) -> double {
        if (0 == b)
        {
            return 0;
        }
        else
        {
            return a/b;
        }
    };

    runDivide(divideLambda);

    std::cout << divideLambda(5.0, 2.0) << std::endl;

    int one = 1;
    int two = 2;
    int three = 3;

    [&](){
        ++one;
        ++two;
        ++three;
    }();

    std::cout << one << " " << two << " " << three << std::endl;

    {
        Test test;
        test.run();
    }

    std::cout << "Functional types: " << std::endl;
    Check chk;
    run(check, "one");
    run(check, "three");
    std::cout << check("one") << std::endl;
    std::cout << check("three") << std::endl;
    run(chk, "one");
    run(chk, "three");
    std::cout << chk("one") << std::endl;
    std::cout << chk("three") << std::endl;

    std::cout << std::endl << "mutable lambdas:" << std::endl;

    int mut{5};

    [mut]() mutable {
        mut = 100;
        std::cout << "mut in lambda: " << mut << std::endl;
    }();

    std::cout << "mut after lambda run: " << mut << std::endl;


    std::cout << std::endl << "Copy Elision:" << std::endl;

    Elide elide = getClass();
    std::cout << elide << std::endl;

    return EXIT_SUCCESS;
}