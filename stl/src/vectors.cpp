#include <iostream>
#include <vector>

/**
 * num_of_elems - a number of elements to iterate over
*/
void iterating_over_vectors(int num_of_elems)
{
    std::vector<int> ints;

    for (int i = 0; i < num_of_elems; ++i)
    {
        ints.push_back(i+1);
    }

    for (int i = 0; i < ints.size(); ++i)
    {
        std::cout << ints[i] << std::endl;
    }

    for (std::vector<int>::iterator it = ints.begin(); it != ints.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void vectors_and_memory()
{
    std::vector<int> ints(0);

    std::cout << ints.size() << std::endl;

    int capacity = ints.capacity();

    for(int i = 0; i < 10000; ++i)
    {
        if(capacity != ints.capacity())
        {
            capacity = ints.capacity();
            std::cout << capacity << "    " << i << std::endl;
        }

        ints.emplace_back(i);
    }

    ints.resize(64);
    ints.shrink_to_fit();
    ints.push_back(7);
    std::cout << "Size : " << ints.size() << std::endl;
    std::cout << "Capacity : " << ints.capacity() << std::endl;
}

void two_dimensional_vectors_iterator()
{
    std::vector< std::vector<int> > ints(12, std::vector<int>(12, 5));

    for(std::vector<std::vector<int>>::iterator row = ints.begin(); row != ints.end(); ++row)
    {
        for(std::vector<int>::iterator col = row->begin(); col != row->end(); ++col)
        {
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void two_dimensional_vectors_index()
{
    std::vector< std::vector<int> > ints(12, std::vector<int>(12, 6));

    for(int row = 0; row < ints.size(); ++row)
    {
        for(int col = 0; col < ints[row].size(); ++col)
        {
            std::cout << ints[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    iterating_over_vectors(4);

    vectors_and_memory();

    two_dimensional_vectors_iterator();

    two_dimensional_vectors_index();
}