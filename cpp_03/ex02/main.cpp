/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:49:16 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	int n = 0;

	std::cout << "=== SCAVTRAP TEST ===" << std::endl;
	ScavTrap s("Serena");
	n++;
	s.attack("target dummy");
	s.guardGate();

	ScavTrap s2 = s;
	n++;
	s2.attack("copy target dummy");

	std::cout << "\n=== FRAGTRAP TEST ===" << std::endl;
	FragTrap f("Freddy");
	n++;
	f.attack("evil bot");
	f.highFivesGuys();

	std::cout << "\n=== COPY TEST ===" << std::endl;
	FragTrap f2 = f;
	n++;
	f2.attack("copy target");

	std::cout << "\n=== DESTRUCTORS SHOULD HAPPEN HERE. (ABOUT " << n << " TIMES) ===" << std::endl;
	return 0;
}
