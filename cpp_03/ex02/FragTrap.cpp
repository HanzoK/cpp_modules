/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:35:06 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:52:16 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_maxHealth = 100;
	_hitPoints = _maxHealth;
	_maxEnergyPoints = 100;
	_energyPoints = _maxEnergyPoints;
	_damage = 30;
	std::cout << "I am FragTrap! Oh Boy, am i happy to be here!\n"
		<< "Here are MY stats:\n"
		<< "HP: " << _hitPoints << "\nEP: " << _energyPoints
		<< "\nDamage: " << _damage << "\n" <<  std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor has been launched!" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	_name = other._name;
	_maxHealth = other._maxHealth;
	_maxEnergyPoints = other._maxEnergyPoints;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_damage = other._damage;
	std::cout << "FragTrap assignment operator has been launched!\n" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " joyfully clocking out for this shift!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
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
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
		<< _damage << " gigatons of damage!\n" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {

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
		std::cout << "FragTrap " << _name << " takes an ungodly amount of "
			<< amount << " damage!!!\n" << std::endl;
		if (static_cast<int>(_hitPoints) < 0) {
			_hitPoints = 0;
		}
	}
}

void FragTrap::beRepaired(unsigned int amount) {
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
		std::cout << "FragTrap " << _name
			<< " has been fatally wounded! Time to heal a duckton of "
			<< amount
			<< " HP!!! Wait. But I can only have a maximum of " << _maxHealth << " HP?! What "
			"are you doing, Player?!!!\n"
			<< std::endl;
	} else
	std::cout << "FragTrap " << _name
		<< " has been fatally wounded! Time to heal a duckton of "
		<< amount << " HP!!!\n" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests high fives! ✋" << std::endl;
}
