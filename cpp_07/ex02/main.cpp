#include <iostream>
#include "Array.hpp"

int main() {
	// empty array
	std::cout << "=== EMPTY ARRAY ===" << std::endl;
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// normal int array
	std::cout << "=== INT ARRAY B (SIZE 5) ===" << std::endl;
	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = static_cast<int>(i * 10);

	std::cout << "b contents: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	//----------------------------------------------------------
	// negative size test
	std::cout << "=== NEGATIVE SIZE TEST ===" << std::endl;
	try {
		Array<int> bad(-5);  // this should throw
		std::cout << "This line will never be reached" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Caught exception for negative size: "
			<< e.what() << std::endl;
	}
	std::cout << std::endl;

	//--------------------------------------------------------------
	std::cout << "=== B COPY ===" << std::endl;
	std::cout << "b content: ";
	for (unsigned int i = 0; i < b.size(); i++)
		try {
			std::cout << b[i] << " ";
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// copy
	std::cout << "=== C (COPY OF B) ===" << std::endl;
	Array<int> c(b);
	std::cout << "c (copy of b) contents: ";
	for (unsigned int i = 0; i < c.size(); i++)
		try {
			std::cout << c[i] << " ";
		} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// modify c to show b is unchanged
	std::cout << "=== MODIFICATION TO DEEP COPY ===" << std::endl;
	try {
		c[0] = 999;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "After c[0] = 999:" << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "c[0] = " << c[0] << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// assignment operator
	std::cout << "=== ASSIGNING B TO D (COPY VALUES FROM B TO D) ===" << std::endl;
	Array<int> d;
	try {
		d = b;
	  } catch (const std::exception &e) {
	  	std::cout << "Exception: " << e.what() << std::endl;
	  }

	std::cout << "d (assigned from b) contents: ";
	for (unsigned int i = 0; i < d.size(); i++)
		try {
			std::cout << d[i] << " ";
	  	} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// test with strings
	std::cout << "=== STRINGS ===" << std::endl;
	Array<std::string> s(3);
	s[0] = "hello";
	s[1] = "42";
	s[2] = "vienna";

	std::cout << "s contents: ";
	for (unsigned int i = 0; i < s.size(); i++)
		try {
			std::cout << s[i] << " ";
	  	} catch (const std::exception &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	//--------------------------------------------------------------
	// faulty index test
	std::cout << "=== OUT-OF-BOUNDS TEST ===" << std::endl;
	try {
		std::cout << "Trying s[3]" << std::endl;
		std::cout << s[3] << std::endl; // should throw
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
