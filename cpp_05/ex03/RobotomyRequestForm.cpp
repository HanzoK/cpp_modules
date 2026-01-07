#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("ROBOT", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("ROBOT", 72, 45) {
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	if (this != &copy) {
		_target = copy._target;
	}
	return (*this);
}

void RobotomyRequestForm::doExecute() const {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << std::endl;
}
