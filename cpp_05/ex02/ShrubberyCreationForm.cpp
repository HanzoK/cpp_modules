#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SHRUB", 147, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("SHRUB", 147, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
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
	std::cout << "Check your folder for some nice ASCII art!" << std::endl;
}
