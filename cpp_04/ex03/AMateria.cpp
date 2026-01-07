/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:20:04 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 23:02:39 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : type(type) {
	std::cout << "\nAMateria constructor called for type: " << type << "\n";
}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {
	/*std::cout << "AMateria copy constructor called for type: " << type << std::endl;*/
}

AMateria& AMateria::operator=(const AMateria&) {
	/*if (this != &copy) {*/
	/*	this->type = copy.type;*/
	/*}*/
	return *this;
}

AMateria::~AMateria() {
	std::cout << "\nAMateria destructor called for type: " << type << std::endl;
}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter&) {
	/*std::cout << "AMateria of type " << type << " used on " << target.getName() << std::endl;*/
}
