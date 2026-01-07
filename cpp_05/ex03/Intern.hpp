#pragma once 

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

struct FormType {
    std::string formName;
    AForm* (*create)(std::string const &target);
};

class Intern {
	private:
	    static AForm *robotomyForm(std::string const &target);
	    static AForm *presidentialForm(std::string const &target);
	    static AForm *shrubberyForm(std::string const &target);
	
	public:
	    Intern();
	    Intern(Intern const &copy);
	    ~Intern();
	    Intern &operator=(Intern const &copy);
	
	    AForm *makeForm(std::string const &name, std::string const &target);
};
