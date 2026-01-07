/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:30 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/05 14:15:38 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	/*this->type = "Dog";*/
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

Dog::~Dog(){
}

void Dog::makeSound() const {
	std::cout << "What does the dog say? Woof woof!" << std::endl;
}

const std::string Dog::getType() const {
	return this->type;
}
