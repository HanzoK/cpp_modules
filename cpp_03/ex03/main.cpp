/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 21:11:35 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	std::cout << "=== DIAMONDTRAP TEST ===" << std::endl;
	DiamondTrap d("DiaBot");

	d.attack("ShadowDummy");
	std::cout << std::endl;
	d.whoAmI();

	std::cout << "=== COPY TEST ===" << std::endl;
	DiamondTrap d2 = d;
	std::cout << "WHO AM I?!" << std::endl;
	d2.whoAmI();

	std::cout << "=== DECONSTRUCTORS FOR ALL OBJECTS RUNNING ===" << std::endl;
	return 0;
}
