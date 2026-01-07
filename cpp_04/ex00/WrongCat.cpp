/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:33:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/05 14:42:51 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "[WrongCat] has been given life!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	type = copy.type;
	std::cout << "[WrongCat] has been copied!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	if (this != &copy) {
		type = copy.type;
		std::cout << "[WrongCat] has been assigned!" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] has been annihilated!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] says: Meow (but wrong, motherducker!)" << std::endl;
}
