/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:46 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:47:56 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _maxHealth(10), _hitPoints(10), _energyPoints(10),
      _damage(0) {
  std::cout << "ClapTrap reporting for duty!\n"
            << "I have the following stats:\n"
            << "HP: " << _hitPoints << "\nEP: " << _energyPoints
            << "\nDamage: " << _damage << "\n" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  _hitPoints = copy._hitPoints;
  _energyPoints = copy._energyPoints;
  _damage = copy._damage;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap signing off for now. Duck you, Player!!! *WHOOOOSH*\n"
            << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
  if (this != &copy) {
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _damage = copy._damage;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (_hitPoints == 0) {
    std::cout << "Ow... Command Center! What's the status of my Health?!\n "
                 "*Command Center*: Looks like you have "
              << _hitPoints
              << " / 10 left! \nOh What? WHY?! ugh, looks like ClapTrap's out, "
                 "folks!\n"
              << std::endl;
    return;
  }

  if (_energyPoints == 0) {
    std::cout
        << "Huff Huff... Looks like I am out of energy points... Hey! Since "
           "when does a ClapTrap have lungs?! I am a robot for god's sake!"
        << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _damage << " gigatons of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

  if (amount >= _hitPoints)
    _hitPoints = 0;
  if (_hitPoints == 0) {
    (std::cout
     << "Ow... Command Center! What's the status of my Health?!\n *Command "
        "Center*: Looks like you have "
     << _hitPoints
     << " / 10 left! \nOh What? WHY?! ugh, looks like ClapTrap's out, folks!\n"
     << std::endl);
    return;
  }

  else {
    _hitPoints = _hitPoints - amount;
    std::cout << "ClapTrap " << _name << " takes an ungodly amount of "
              << amount << " damage!!!" << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "Ow... Command Center! What's the status of my Health?!\n "
                 "*Command Center*: Looks like you have "
              << _hitPoints
              << " / 10 left! \nOh What? WHY?! ugh, looks like ClapTrap's out, "
                 "folks!\n"
              << std::endl;
    return;
  }

  if (_energyPoints == 0) {
    std::cout
        << "Huff Huff... Looks like I am out of energy points... Hey! Since "
           "when does a ClapTrap have lungs?! I am a robot for god's sake!"
        << std::endl;
    return;
  }

  _energyPoints--;
  _hitPoints = amount + _hitPoints;
  if (_hitPoints > _maxHealth) {
    _hitPoints = 10;
    std::cout << "ClapTrap " << _name
              << " has been fatally wounded! Time to heal a duckton of "
              << amount
              << " HP!!! Wait. But I can only have a maximum of 10 HP?! What "
                 "are you doing, Player?!!!"
              << std::endl;
  } else
    std::cout << "ClapTrap " << _name
              << " has been fatally wounded! Time to heal a duckton of "
              << amount << " HP!!!" << std::endl;
}
