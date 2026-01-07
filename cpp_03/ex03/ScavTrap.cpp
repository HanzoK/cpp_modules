/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:12:28 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/29 15:32:54 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) { 
	_maxHealth = 100; 
	_hitPoints = _maxHealth;
	_energyPoints = 50;
	_damage = 20;
	std::cout << "I am ScavTrap... Why am i here though?\n"
		<< "Here are MY stats:\n"
		<< "HP: " << _hitPoints << "\nEP: " << _energyPoints
		<< "\nDamage: " << _damage << "\n" <<  std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " annihilated!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _damage << " gigatons of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " can't guard the gate!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
}

unsigned int ScavTrap::getEnergyPoints() const {
	return _energyPoints;
}
