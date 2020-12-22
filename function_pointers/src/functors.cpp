#include <iostream>

struct Test
{
    virtual bool operator()(const std::string &text) = 0;

    virtual ~Test(){}
};

struct MatchTest : public Test
{
    bool operator()(const std::string &text)
    {
        return text == "lion";
    }
};

void check(const std::string &text, Test &test)
{
    if(test(text))
    {
        std::cout << "Text matches" << std::endl;
    }
    else
    {
        std::cout << "No match" << std::endl;
    }
}

int main()
{   
    std::string val = "lion";
    std::string val2 = "monkey";

    MatchTest pred;
    check(val, pred);
    check(val2, pred);

    return EXIT_SUCCESS;
}