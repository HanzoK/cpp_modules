/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:52:34 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 22:30:30 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
public:
	Character(const std::string &name);
	Character(const Character &other);
	Character& operator=(const Character &other);
	virtual ~Character();

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string name;
	AMateria* inventory[4];
	AMateria* floor[100];
	int floorCount;
};
