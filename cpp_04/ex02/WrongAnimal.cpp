/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:26:53 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/05 14:43:04 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] has been given life " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "[WrongAnimal] has been copied " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << "[WrongAnimal] has been assigned " << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] has been nuked " << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] makes a wrong generic sound" << std::endl;
}
