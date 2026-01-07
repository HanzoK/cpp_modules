/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:52:48 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/28 20:35:29 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {

public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int getHitpoints();
	
protected:
	std::string _name;
	unsigned int _maxHealth;
	unsigned int _maxEnergyPoints;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _damage;
} ;
