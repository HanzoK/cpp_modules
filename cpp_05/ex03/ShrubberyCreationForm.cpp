#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUB", 147, 137) {
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("SHRUB", 147, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	// std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

void ShrubberyCreationForm::doExecute() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    ofs << "       ccee88oo\n";
    ofs << "  C8O8O8Q8PoOb o8oo\n";
    ofs << " dOB69QO8PdUOpugoO9bD\n";
    ofs << "CgggbU8OU qOp qOdoUOdcb\n";
    ofs << "    6OuU  /p u gcoUodpP\n";
    ofs << "      \\\\//  /douUP\n";
    ofs << "        \\\\////\n";
    ofs << "         |||/\\\n";
    ofs << "         |||\\/\n";
    ofs << "         |||||\n";
    ofs << "   .....//||||\\....\n";
    ofs.close();
}
