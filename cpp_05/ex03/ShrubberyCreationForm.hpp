#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
    
    protected:
        void doExecute() const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

		virtual ~ShrubberyCreationForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};