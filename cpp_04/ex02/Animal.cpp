/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:20 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:05:17 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")  {
	std::cout << "[Animal] Default constructor called (abstract, type=" << type << ")" << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type) {
	std::cout << "[Animal] Copy constructor called (abstract, type=" << type << ")" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "[Animal] Copy assignment operator called (abstract, type=" << copy.type << ")" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "[Animal] Destructor called (abstract, type=" << type << ")" << std::endl;
}

const std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "Animal makes completely normal sound... right?" << std::endl;
}
