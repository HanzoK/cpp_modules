#include <iostream>
#include "Base.hpp"
#include "Identify.hpp"
#include <ctime>
#include <cstdlib>

// randomly create A, B, or C
Base* generate(void) {
	int r = 0;

    static bool instant = false;
    if (!instant) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        instant = true;
    }
    r = std::rand() % 3;
    switch (r) {
        case 0: 
			std::cout << "Generated: A\n"; 
			return new A();
        case 1: 
			std::cout << "Generated: B\n"; 
			return new B();
        case 2: 
			std::cout << "Generated: C\n"; 
			return new C();
		default:
			std::cout << "lol" << std::endl;
			return NULL;
    }
}

// identify using pointer
void identify(Base* p) {
    if (!p) { 
		std::cout << "Pointer is null" << std::endl; 
		return; }
    if (dynamic_cast<A*>(p)) 
		std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
		std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
		std::cout << "C" << std::endl;
    else 
		std::cout << "What is this type?!" << std::endl;
}

// identify using reference
void identify(Base& p) {
    // dynamic_cast to references throws
    try { 
		(void)dynamic_cast<A&>(p); 
		std::cout << "A" << std::endl; 
		return; } 
	catch (...) {}
    try { 
		(void)dynamic_cast<B&>(p); 
		std::cout << "B" << std::endl; 
		return; } 
	catch (...) {}
    try { 
		(void)dynamic_cast<C&>(p); 
		std::cout << "C" << std::endl; 
		return; } 
	catch (...) {}
    std::cout << "Unknown type\n";
}
