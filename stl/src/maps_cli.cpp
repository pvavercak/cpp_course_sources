#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <string.h>

void basic_map_operations()
{
    std::map<std::string, int> ages;

    ages["Raj"] = 40;
    ages["Mike"] = 20;
    ages["John"] = 30;

    std::pair<std::string, int> george{"George", 50};

    ages.insert(george);
    ages.insert(std::make_pair("Peter", 60));

    for(std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << " (iterator)" << std::endl;
        std::pair<std::string, int> it2pair = *it;
        std::cout << it2pair.first << ": " << it2pair.second << " (std::pair)" << std::endl;
    }
}

void read_the_database(std::map<std::string, int> &database)
{
    std::ifstream database_file;
    database_file.open("db.txt");

    if(database_file.is_open())
    {
        while(database_file)
        {
            std::string name;
            std::getline(database_file, name, ':');

            int age = 0;
            database_file >> age >> std::ws;

            if("" != name)
            {
                database.insert(std::make_pair(name, age));
            }
            

            if(!database_file)
            {
                break;
            }
        }
        database_file.close();
    }
}

void save_to_database(std::map<std::string, int> &database)
{
    std::ofstream database_file;

    database_file.open("db.txt");

    if(database_file.is_open())
    {
        for(auto it = database.begin(); it != database.end(); ++it)
        {
            database_file << it->first << ":" << it->second << std::endl;
        }
        database_file.close();
    }
}

/**
 * A simple cli application, definitelly not user-friendly
 */
int main(int argc, char** argv)
{
    std::map<std::string, int> db;
    read_the_database(db);

    if(argc != 3 && argc != 4) {
        std::cout << "Usage:" << std::endl;
        std::cout << "maps search <name>"<< std::endl;
        std::cout << "maps add <name>"<< std::endl;
        std::cout << "maps remove <name>"<< std::endl;
        return EXIT_FAILURE;
    }

    auto findIt = db.find(argv[2]);

    if(0 == strncmp(argv[1], "search", 5))
    {
        if (db.end() == findIt)
        {
            std::cout << "No such name in the database" << std::endl;
            return EXIT_SUCCESS;
        }
        std::cout << findIt->first << " is " << findIt->second << " years old" << std::endl;
    }
    else if(0 == strncmp(argv[1], "remove", 6))
    {
        if (db.end() == findIt)
        {
            std::cout << "No such name in the database" << std::endl;
            return EXIT_SUCCESS;
        }
        db.erase(findIt);
    }
    else if(0 == strncmp(argv[1], "add", 3))
    {
        if(argc != 4) {
            std::cout << "Provide age parameter" <<std::endl;
            return EXIT_FAILURE;
        }
        if (db.end() != findIt)
        {
            std::cout << "Updating " << argv[2] << "'s age" << std::endl;
        }
        db[argv[2]] = std::stoi(argv[3]);
    }
    else
    {
        std::cout << "Bad action" << std::endl;
        return 2;
    }

    save_to_database(db);

    return EXIT_SUCCESS;
}
