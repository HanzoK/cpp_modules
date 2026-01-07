#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("BOB", 1);
		Bureaucrat loser("Loser", 150);
        ShrubberyCreationForm shrubbery("42");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
		std::cout << std::endl;
        // Signing forms
        try {
			bob.signForm(shrubbery);
			loser.signForm(shrubbery);
            std::cout << "ShrubberyCreationForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during ShrubberyCreationForm signing: " << e.what() << std::endl;
        }
        try {
			bob.signForm(robotomy);
			loser.signForm(robotomy);
            std::cout << "RobotomyRequestForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during RobotomyRequestForm signing: " << e.what() << std::endl;
        }

        try {
			bob.signForm(pardon);
			loser.signForm(pardon);
            std::cout << "PresidentialPardonForm signed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during PresidentialPardonForm signing: " << e.what() << std::endl;
        }
		std::cout << std::endl;
        std::cout << shrubbery << " by " << bob.getName() << ")" << std::endl;
        std::cout << robotomy << " by " << bob.getName() << ")" << std::endl;
        std::cout << pardon << " by " << bob.getName() << ")" << std::endl;
		std::cout << std::endl;

        // Executing forms
        try {
            bob.executeForm(shrubbery);
            loser.executeForm(shrubbery);
            std::cout << "ShrubberyCreationForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during ShrubberyCreationForm execution: " << e.what() << std::endl;
        }
		std::cout << std::endl;

        try {
            bob.executeForm(robotomy);
            loser.executeForm(robotomy);
            std::cout << "RobotomyRequestForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during RobotomyRequestForm execution: " << e.what() << std::endl;
        }
		std::cout << std::endl;

        try {
            bob.executeForm(pardon);
            loser.executeForm(pardon);
            std::cout << "PresidentialPardonForm executed successfully." << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception during PresidentialPardonForm execution: " << e.what() << std::endl;
        }
		try {
			std::string bad = NULL;
			RobotomyRequestForm really_bad = RobotomyRequestForm(bad);

            bob.executeForm(really_bad);
            loser.executeForm(really_bad);
			std::cout << "PresidentialPardonForm executed successfully." << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Exception during PresidentialPardonForm execution: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
    }
	catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
