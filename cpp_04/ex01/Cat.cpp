/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:48:00 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/06 15:00:54 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	brain = new Brain();
	std::cout << "[Cat] default constructed" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->type = "Cat";
	this->brain = new Brain(*copy.brain);
	std::cout << "[Cat] copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "[Cat] assigned" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		*brain = *copy.brain;
		this->type = copy.type;
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "[Cat] destructed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "What does the kitty say? Meow meow!" << std::endl;
}

const std::string Cat::getType() const {
	return this->type;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
