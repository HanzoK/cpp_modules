/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:37:10 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 22:53:20 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "\nIce conjured!" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	/*std::cout << "Ice conjured by copy!" << std::endl;*/
}

Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy)
		AMateria::operator=(copy);
	/*std::cout << "Ice assigned!" << std::endl;*/
	return *this;
}

Ice::~Ice() {
	std::cout << "\nIce melted!" << std::endl;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	/*AMateria::use(target);*/
}
