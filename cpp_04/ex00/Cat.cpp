/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:48:00 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/05 14:15:51 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	this->type = "Cat";
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

Cat::~Cat() {
}

void Cat::makeSound() const {
	std::cout << "What does the kitty say? Meow meow!" << std::endl;
}

const std::string Cat::getType() const {
	std::cout << "yo wtf?" << std::endl; //delete later
	return this->type;
}
