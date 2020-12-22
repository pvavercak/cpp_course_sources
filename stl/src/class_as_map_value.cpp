#include <iostream>
#include <map>

class Person {
private:
    std::string name;
    int age;

public:
    Person() : name(""), age(0)
    {
        ;
    }

    Person(const std::string &name, int age) :
        name(name),
        age(age)
    {
        std::cout << "copy constructor running!" << std::endl;
    }

    void print() const
    {
        std::cout << name << ": " << age << std::flush;
    }

    bool operator<(const Person &other) const
    {
        if (name == other.name)
        {
            return age < other.age;
        }
        else {
            return name < other.name;
        }
    }
};

void class_as_value()
{
    std::map<int, Person> people;

    people[10] = Person("Mike", 30);
    people[50] = Person("Adam", 18);
    people[20] = Person("Raj", 40);

    people.insert(std::make_pair(25, Person("Patrik", 23)));
    people.insert(std::make_pair(25, Person("Joe", 33)));

    for(auto it = people.begin(); it != people.end(); ++it)
    {
        std::cout << it->first << ": " << std::flush;
        it->second.print();
        std::cout << std::endl;
    }
}


void class_as_key()
{
    std::map<Person, int> people;

    people[Person("Mike", 40)] = 40;
    people[Person("Joe", 999)] = 1225;
    people[Person("Joe", 50)] = 30;
    people[Person("Peter", 40)] = 20;

    for(std::map<Person, int>::iterator it = people.begin(); it != people.end(); ++it)
    {
        std::cout << it->second << ": " << std::flush;
        it->first.print();
        std::cout << std::endl;
    }
}

void multimap_exercise()
{
    std::multimap<std::string, int> people;

    people.insert(std::make_pair("Mike", 40));
    people.insert(std::make_pair("John", 80));
    people.insert(std::make_pair("George", 70));
    people.insert(std::make_pair("George", 30));

    for(std::multimap<std::string, int>::iterator it = people.begin(); it != people.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::pair< std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator > its = people.equal_range("George");
    std::cout << std::endl;
    for(std::map<std::string, int>::iterator it2 = its.first; it2 != its.second; ++it2)
    {
        std::cout << it2->first << ": " << it2->second << std::endl;
    }
}

int main()
{
    // class_as_key();

    multimap_exercise();

    return EXIT_SUCCESS;
}