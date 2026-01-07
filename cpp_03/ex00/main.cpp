/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/29 18:03:32 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clap("CL4P-TP");

	std::cout << std::endl;
	std::cout << "FIGHT 1\n" << std::endl;
	clap.attack("Bandit");
	clap.takeDamage(8);
	if (clap.getHitPoints() == 0)
		return 0;
	clap.beRepaired(5);

	std::cout << std::endl;

	std::cout << "FIGHT 2\n" << std::endl;
	clap.takeDamage(6);
	if (clap.getHitPoints() == 0)
		return 0;
	clap.attack("Psycho");
	clap.beRepaired(9);
	std::cout << std::endl;

	return 0;
}
