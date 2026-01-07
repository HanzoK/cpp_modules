#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("SOMEBODYYOU USED TO KNOW"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(const std::string &name, int gs, int ge) : _name(name), _signed(false), _gradeToSign(gs), _gradeToExecute(ge) {
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy)
        _signed = copy._signed;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &burro) {
    if (burro.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!_signed)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    doExecute();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high, dawg.";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low, dawg.";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Not Signed, fam.";
}

std::ostream &operator<<(std::ostream &output, const AForm &f) {
    output << f.getName() << " (signed: ";
    if (f.isSigned())
        output << "signed,";
    else 
        output << "not signed"
    << ", grade sign: " << f.getGradeToSign()
    << ", grade exec: " << f.getGradeToExecute() << ")";
    return output;
}
