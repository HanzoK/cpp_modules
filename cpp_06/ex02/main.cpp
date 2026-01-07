#include "Identify.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) 
	{
        Base* p = generate();
        // Base* p = NULL;

        std::cout << "identify(Base*): ";
        identify(p);

        std::cout << "identify(Base&): ";
        identify(*p);

        delete p;
        std::cout << std::endl;
    }

    std::cout << "identify(Base* nullptr): ";
    identify(static_cast<Base*>(NULL));

    return 0;
}
