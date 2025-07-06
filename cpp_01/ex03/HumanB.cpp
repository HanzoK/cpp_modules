/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:43 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:57:22 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	nWeapon = NULL;
	std::cout << name << " has been born." << std::endl;
}

HumanB::~HumanB() {
	std::cout << name << " has been snapped out of existence." << std::endl;
}

void HumanB::attack() {
	if (!nWeapon)
		std::cout << name << " has not enough IQ to find a weapon." << std::endl;
	else
		std::cout << name << " attacks with their " << nWeapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon) {
	nWeapon = &newWeapon;
}
