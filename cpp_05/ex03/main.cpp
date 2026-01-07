#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "Intern creates forms" << std::endl;

    Intern intern;
    AForm *f1 = intern.makeForm("robotomy request", "Bender");
    AForm *f2 = intern.makeForm("shrubbery creation", "home");
    AForm *f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm *f4 = intern.makeForm("invalid form", "nobody"); // should print error

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);
    Bureaucrat low("Low", 150);
	std::cout << std::endl;

	std::cout << "Intern creates forms" << std::endl;
    if (f1) mid.signForm(*f1);  // mid CANNOT sign robotomy (needs 72, mid=70 → OK)
	std::cout << std::endl;
    if (f2) low.signForm(*f2);  // low CANNOT sign shrubbery (needs 145, low=150 → fail)
	std::cout << std::endl;
    if (f3) boss.signForm(*f3); // boss signs successfully
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Intern creates forms" << std::endl;
    if (f1) boss.executeForm(*f1); // robotomy, success/fail randomly
	std::cout << std::endl;
    if (f2) boss.executeForm(*f2); // shrubbery, boss executes fine
	std::cout << std::endl;
    if (f3) boss.executeForm(*f3); // pardon, works
	std::cout << std::endl;

	std::cout << "Intern creates forms" << std::endl;
    if (f2 && !f2->isSigned())
		low.executeForm(*f2); // should fail: form unsigned + low grade
	std::cout << std::endl;
	
	std::cout << "Intern deletes forms" << std::endl;
    delete f1;
    delete f2;
    delete f3;
    delete f4; // safe even if NULL

    std::cout << "\nAll tests done.\n";
    return 0;
}
