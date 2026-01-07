/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:41:12 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 23:06:17 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "\nPreparing cure cast!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
	/*std::cout << "Cure copy constructor called!" << std::endl;*/
}

Cure &Cure::operator=(const Cure &copy) {
	if (this != &copy)
		AMateria::operator=(copy);
	/*std::cout << "Cure assignment operator called!" << std::endl;*/
	return *this;
}

Cure::~Cure() {
	std::cout << "\nCure Faded!" << std::endl;
}

AMateria *Cure::clone() const {
	/*std::cout << "Cure clone called!" << std::endl;*/
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	/*AMateria::use(target);*/
}
