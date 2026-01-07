#pragma once 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
    
    protected:
        void doExecute() const;
        
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
		void execute(Bureaucrat const &executor) const;
};