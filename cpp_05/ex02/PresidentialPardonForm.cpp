#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PRESIDENT", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PRESIDENT", 25, 5) {
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy) {
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	if (this != &copy) {
		_target = copy._target;
	}
	return (*this);
}

void PresidentialPardonForm::doExecute() const {
    std::cout << _target
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
