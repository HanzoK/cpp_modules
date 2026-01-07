#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("SOMEBODY YOU USED TO KNOW"), _grade(1) {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        _grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high, Dawg.\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low, Pal.\n";
}

void Bureaucrat::signForm(AForm &f) const {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName();
    } catch (std::exception &ex) {
        std::cout << _name << " not able to sign" << f.getName() << " due to " << ex.what();
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &B) {
    output << B.getName() << ", Bureaucrat grade " << B.getGrade() << ".";
    return output;
}
