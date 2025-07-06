/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:09 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:48:19 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name) , nWeapon2(weapon) {
	std::cout << name << " has been born." << std::endl;
}

HumanA::~HumanA() {
	std::cout << name << " has been snapped out of existence." << std::endl;
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << nWeapon2.getType() << std::endl;
}
