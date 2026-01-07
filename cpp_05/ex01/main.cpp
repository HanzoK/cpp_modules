#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat burroA("BurroA", 50);
		Form formA("FormA", 50, 49);
		std::cout << burroA << std::endl;
		std::cout << formA << std::endl;
		burroA.incrementGrade();
		formA.beSigned(burroA);
		burroA.signForm(formA);
	}
	catch (const std::exception &exe) {
		std::cerr << exe.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	try {
		Bureaucrat burroB("BiroB", 25);
		Form formB("FormB", 15, 10);
		std::cout << burroB << std::endl;
		std::cout << formB << std::endl;
		burroB.incrementGrade();
		burroB.signForm(formB);
	}
	catch (const std::exception &exe) {
		std::cerr << exe.what() << std::endl;
	}
    return 0;
}
