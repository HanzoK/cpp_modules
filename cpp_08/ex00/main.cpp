#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i);
        std::cout << "searching for number in vector. Please wait..." << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "number found: " << *it << std::endl;

        std::cout << "searching for number in vector. Please wait..." << std::endl;
        it = easyfind(vec, 10); // will throw here because 10 is not in vector
        std::cout << "number found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception found: " << e.what() << std::endl;
    }

    try
    {
        std::list<int> lst;
        lst.push_back(42);
        lst.push_back(100);
        lst.push_back(7);

        std::cout << "searching for number in list. Please wait..." << std::endl;
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "number found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "exception found: " << e.what() << std::endl;
    }

    return 0;
}
