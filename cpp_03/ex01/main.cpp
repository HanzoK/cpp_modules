/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:26:30 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

	/*unsigned int damage = -1;*/

	ScavTrap s("Serena");
	s.takeDamage(990);
	s.beRepaired(100);
	/*if (static_cast<int>(damage) < 0) {*/
	/*	return 0;*/
	/*}*/
	/**/
	s.attack("target dummy");
	s.guardGate();

	/*std::cout << std::endl;*/
	std::cout << "***TESTING COPY CONSTRUCTOR AND COPY ASSIGNMENT IN THIS INSTANCE:***\n" << std::endl;
	ScavTrap copy = s;
	std::cout << "HP: " << copy.getHitPoints() << std::endl;
	std::cout << "EP: " << copy.getEnergyPoints() << std::endl;
	if (copy.getGateMode() == 1) {
		std::cout << "Gatekeeper mode: Yes\n" << std::endl;
	} else {
		std::cout << "Gatekeeper mode: No\n" << std::endl;
	}
	copy.attack("another dummy");
	std::cout << "***2 DESCTRUCTOS MUST BE CALLED HERE: 1 FOR 1ST OBJECT, 2ND ONE FOR 2ND OBJECT!!!***\n" << std::endl;

	return 0;
}
