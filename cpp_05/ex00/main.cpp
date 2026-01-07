#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("b1", 5);
		std::cout << b1 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;

	// This will throw an exception
	try {
		Bureaucrat b2("b2", 152);
		std::cout << b2 << std::endl;
		std::cout << "Before increment: " << b2 << std::endl;
		b2.incrementGrade();
		std::cout << "After increment: " << b2 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}

	try {
		Bureaucrat b3("b3", 150);
		std::cout << b3 << std::endl;
		std::cout << "Before increment: " << b3 << std::endl;
		b3.incrementGrade();
		std::cout << "After increment: " << b3 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat b4("b4", 151); // This will throw an exception
		std::cout << b4 << std::endl;
		std::cout << "Before increment: " << b4 << std::endl;
		b4.incrementGrade();
		std::cout << "After increment: " << b4 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	
	try {
		Bureaucrat b5("b5", 150);
		std::cout << b5 << std::endl;
		std::cout << "Before decrement: " << b5 << std::endl;
		b5.decrementGrade(); // This will throw an exception
		std::cout << "After decrement: " << b5 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}

	Bureaucrat *b6;
	try {
		b6 = new Bureaucrat("b6", 149);
		std::cout << *b6 << std::endl;
		std::cout << "Before decrement: " << *b6 << std::endl;
		b6->decrementGrade();
		std::cout << "After decrement: " << *b6 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	delete b6;
	std::cout << std::endl;
	
	Bureaucrat *b7;
	try {
		b7 = new Bureaucrat();
		std::cout << *b7 << std::endl;
		std::cout << "Before decrement: " << *b7 << std::endl;
		b7->decrementGrade(); // This will throw an exception
		std::cout << "After decrement: " << *b7 << std::endl;
	}
	catch (const std::exception &exe) {
		std::cerr << "Exception caught: " << exe.what() << std::endl;
	}
	delete b7;
	return 0;
}
