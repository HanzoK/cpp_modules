#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    protected:
        AForm();
        virtual void doExecute() const = 0;

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExec);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
        void execute(Bureaucrat const &executor) const;

        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
        };

        class NotSignedException : public std::exception {
        public:
            const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const AForm &f);
