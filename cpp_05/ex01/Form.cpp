#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gs, int ge) : _name(name), _signed(false), _gradeToSign(gs), _gradeToExecute(ge) {
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

Form::~Form() {}

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &burrito) {
    if (burrito.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high, dawg.";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low, dawg.";
}

std::ostream &operator<<(std::ostream &output, const Form &f) {
    output << f.getName() << " (signed: ";
    if (f.isSigned())
        output << "signed,";
    else 
        output << "not signed"
    << ", grade sign: " << f.getGradeToSign()
    << ", grade exec: " << f.getGradeToExecute() << ")" << std::endl;
    return output;
}
