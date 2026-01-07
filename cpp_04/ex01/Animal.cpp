/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:20 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/12 16:47:49 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")  {
}

Animal::Animal(const Animal& copy) : type(copy.type) {
	// copy constructor
	// this will copy the type from the copied Animal object
	// no need to do anything else since we are not managing resources
	// like dynamic memory in this class
}

Animal& Animal::operator=(const Animal& copy) {
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

Animal::~Animal(){
}

const std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "[Animal] makes completely normal sound... right?" << std::endl;
}
