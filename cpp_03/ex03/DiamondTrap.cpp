/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:40:49 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/29 16:50:52 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = 50;
	_damage = FragTrap::_damage;
	std::cout << "The ultimate DiamondTrap is here!\n"
			<< "These are my super awesome stats:\n"
			<< "HP: " << _hitPoints << "\nEP: " << _energyPoints
			<< "\nDamage: " << _damage <<  "\n" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor is in full motions!" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
	if (this != &copy) {
		ClapTrap::operator=(copy);
		ScavTrap::operator=(copy);
		FragTrap::operator=(copy);
		_name = copy._name;
	}
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_damage = copy._damage;
	std::cout << "DiamondTrap assignment operator is in full motions!\n" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " has been crushed(Deconstructed)!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target); // use ScavTrap’s attack
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << _name << ", and my ClapTrap name is " << ClapTrap::_name << ". At your service!\n" << std::endl;
}
