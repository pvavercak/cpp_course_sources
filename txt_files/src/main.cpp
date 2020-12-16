#include <string>
#include <iostream>
#include <fstream>

const static std::string O_FNAME = "out_test_file.txt";
const static std::string I_FNAME = "in_test_file.txt";
const static std::string PARSE_FNAME = "parseme.txt";

void generate_random_text_file()
{
    std::ofstream out_file;

    out_file.open(I_FNAME);

    out_file << "This file contains the following lines:"
             << std::endl;

    for(int i = 0; i < 5; ++i) {
        out_file << "Line "
                 << i + 1
                 << std::endl;
    }
    
    out_file.close();
}

void generate_parseme_file()
{
    std::ofstream output_file;

    output_file.open(PARSE_FNAME);

    output_file << "Population UK: 64000000"
                << std::endl
                << "Population France: 664000000"
                << std::endl;

    output_file.close();
}

void create_file_using_ofstream()
{
    std::ofstream out_file;

    out_file.open(O_FNAME);

    out_file << "A line from create_file_using_ofstream!"
             << std::endl;

    out_file.close();
}

void create_file_using_fstream()
{
	std::fstream out_file;

	// since we used basic fstream object, open mode has to be specified
	out_file.open(O_FNAME, std::ios::out);

	out_file << "A line from create_file_using_fstream!"
			<< std::endl;

	out_file.close();
}

void read_from_text_file()
{
    generate_random_text_file();

    std::ifstream input_file;

    input_file.open(I_FNAME);

    if(input_file.is_open()){
        while(input_file) // or !input_file.eof()
        {
            std::string line;

            std::getline(input_file, line);

            std::cout << line
                    << std::endl;
        }
    }

    input_file.close();
}

void parse_text_file()
{
    generate_parseme_file();

    std::ifstream input_file;

    input_file.open(PARSE_FNAME);

    if(input_file.is_open())
    {
        while(input_file)
        {
            std::string line;

            std::getline(input_file, line, ':');

            int population = 0;

            input_file >> population >> std::ws;

            if(!input_file)
            {
                break;
            }

            std::cout << "'"
                      << line
                      << "'"
                      << " -- "
                      << "'"
                      << population
                      << "'"
                      << std::endl;
        }
    }

    input_file.close();
}

int main()
{
	create_file_using_ofstream();

    create_file_using_fstream();

    read_from_text_file();

    parse_text_file();

	return EXIT_SUCCESS;
}
