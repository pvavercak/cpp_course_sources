#include <iostream>
#include <cstring>
#include <fstream>

const static std::string BIN_FILENAME = "person.bin";

#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double height;

    bool operator==(Person &other)
    {
        return 0 == strcmp(name, other.name) &&
                age == other.age &&
                height == other.height;
    }
};

#pragma pack(pop)

void save_binary_file(Person &person)
{
    std::fstream outputFile;

    outputFile.open(BIN_FILENAME, std::ios::out|std::ios::binary);

    if (outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char *>(&person), sizeof(Person));

        outputFile.close();
    }
}

void load_binary_file(Person &person)
{
    std::fstream inputFile;

    inputFile.open(BIN_FILENAME, std::ios::in|std::ios::binary);

    if (inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char *>(&person), sizeof(Person));

        inputFile.close();
    }
}

int main()
{

    Person p = {"Patrik", 23, 180.0};
    save_binary_file(p);
    
    Person o = {};

    load_binary_file(o);

    if (p == o) {
        std::cout << "Structures are the same:" << std::endl;
        std::cout << p.name << " == " << o.name << std::endl;
        std::cout << p.age << " == " << o.age << std::endl;
        std::cout << p.height << " == " << o.height << std::endl;
    }

    return EXIT_SUCCESS;
}