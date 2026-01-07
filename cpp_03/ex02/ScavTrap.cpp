/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:12:28 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:44:23 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) { 
	_maxHealth = 100; 
	_hitPoints = _maxHealth;
	_maxEnergyPoints = 50;
	_energyPoints = _maxEnergyPoints;
	_damage = 20;
	std::cout << "I am ScavTrap... Why am i here though?\n"
		<< "Here are MY stats:\n"
		<< "HP: " << _hitPoints << "\nEP: " << _energyPoints
		<< "\nDamage: " << _damage << "\n" <<  std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor initiated..." << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	_name = other._name;
	_maxHealth = other._maxHealth;
	_maxEnergyPoints = other._maxEnergyPoints;
	_damage = other._damage;
	std::cout << "ScavTrap assignment operator initiated...\n" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " signing off for today... I ain't doing overtime." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0) {
		_hitPoints = 0;
		std::cout << "Ow... Command Center! What's the status of my Health?!\n "
			"*Command Center*: Looks like you have "
			<< _hitPoints
			<< " / " << _maxHealth << " left! \nOh What? WHY?! ugh, looks like " << _name << "'s out, "
			"folks!\n"
			<< std::endl;
		return;
	}

	if (_energyPoints <= 0) {
		_energyPoints = 0;
		std::cout
			<< "Huff Huff... Looks like I am out of energy points... Hey! Since "
			"when does a " << _name << " have lungs?! I am a robot for god's sake!\n"
			<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _damage << " gigatons of damage!\n" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {

	if (static_cast<int>(amount) < 0) {
		_hitPoints = _maxHealth;
		std::cout << "Why? Just why? Who in the world does negative dmg? Except every adc on my team?!\n" << std::endl;
		return;
	}

	if (_hitPoints == 0) {
		(std::cout
			<< "Ow... Command Center! What's the status of my Health?!\n *Command "
			"Center*: Looks like you have "
			<< _hitPoints
			<< " / " << _maxHealth << " left! \nOh What? WHY?! ugh, looks like" << _name << " 's out, folks!\n"
			<< std::endl);
		return;
	}
	else {
		_hitPoints = _hitPoints - amount;
		std::cout << "ScavTrap " << _name << " takes an ungodly amount of "
			<< amount << " damage!!!\n" << std::endl;
		if (static_cast<int>(_hitPoints) < 0) {
			_hitPoints = 0;
		}
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "Ow... Command Center! What's the status of my Health?!\n "
			"*Command Center*: Looks like you have "
			<< _hitPoints
			<< " / " << _maxHealth << " left! \nOh What? WHY?! ugh, looks like " << _name << "'s out, "
			"folks!\n"
			<< std::endl;
		return;
	}
	_energyPoints--;
	if (_energyPoints <= 0) {
		std::cout
			<< "Huff Huff... Looks like I am out of energy points... Hey! Since "
			"when does a " << _name << " have lungs?! I am a robot for god's sake!"
			<< std::endl;
		return;
	}

	_hitPoints = amount + _hitPoints;
	if (_hitPoints > _maxHealth) {
		_hitPoints = _maxHealth;
		std::cout << "ScavTrap " << _name
			<< " has been fatally wounded! Time to heal a duckton of "
			<< amount
			<< " HP!!! Wait. But I can only have a maximum of " << _maxHealth << " HP?! What "
			"are you doing, Player?!!!\n"
			<< std::endl;
	} else
	std::cout << "ScavTrap " << _name
		<< " has been fatally wounded! Time to heal a duckton of "
		<< amount << " HP!!!\n" << std::endl;
}

void ScavTrap::guardGate() {
	if (static_cast<int>(_hitPoints) <= 0) {
		std::cout << "Yo. ScavTrap " << _name << " can't guard the gate... Out of hitpoints...\n" << std::endl;
		return;
	}
	_energyPoints--;
	if (static_cast<int>(_energyPoints) <= 0) {
		std::cout
			<< "Huff Huff... Looks like I am out of energy points... Can't guard the gate... Hey! Since "
			"when does a " << _name << " have lungs?! I am a robot for god's sake!"
			<< std::endl;
		return;
	}

	std::cout << "ScavTrap " << _name << " is initiating GATEKEEPER MODE!!!\n" << std::endl;
}

unsigned int ScavTrap::getHitPoints() const {
	return _hitPoints;
}
unsigned int ScavTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int ScavTrap::getGateMode() const {
	if (_energyPoints <= 0 || _hitPoints <= 0) {
		return 0;
	}
	return 1;
}
