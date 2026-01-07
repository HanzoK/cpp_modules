/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:30 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 15:54:28 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	brain = new Brain();
	std::cout << "[Dog] default constructed" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << "[Dog] copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "[Dog] assigned" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		this->type = copy.type;
		*brain = *copy.brain;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "[Dog] destructed" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "What does the dog say? Woof woof!" << std::endl;
}

const std::string Dog::getType() const {
	return this->type;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
