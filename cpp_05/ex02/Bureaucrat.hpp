#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
        static void validateGrade(int _grade);

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };

        void signForm(AForm &form) const;
        void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &B);
