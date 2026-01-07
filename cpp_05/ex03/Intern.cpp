#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &copy) {
    *this = copy;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &copy) {
    if (this != &copy) {
        (void)copy;
    }
    return *this;
}

AForm *Intern::robotomyForm(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::presidentialForm(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::shrubberyForm(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
    FormType formTypes[] = {
        {"robotomy request",      &robotomyForm},
        {"presidential pardon",   &presidentialForm},
        {"shrubbery creation",    &shrubberyForm},
    };

    const size_t formCount = sizeof(formTypes) / sizeof(FormType);

    for (size_t i = 0; i < formCount; ++i) {
        const std::string &candidateName = formTypes[i].formName;
        if (candidateName == name) {
            std::cout << "Intern creates form: \"" << name
                      << "\" with target: \"" << target << "\""
                      << std::endl;
            return formTypes[i].create(target);
        }
    }
    
    std::cout << "Intern error: form \"" << name
              << "\" does not exist." << std::endl;

    return NULL;
}
