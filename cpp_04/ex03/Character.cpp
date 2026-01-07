/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:56:54 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/17 16:37:30 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& n) : name(n), floorCount(0) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    for (int i = 0; i < 100; ++i)
        floor[i] = NULL;
    std::cout << "[Character] " << name << " constructed" << std::endl;
}

Character::Character(const Character& other) : name(other.name), floorCount(0) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    for (int i = 0; i < 100; ++i) {
		if (other.floor[i])
        	floor[i] = other.floor[i]->clone();
		else
			floor[i] = NULL;
    }
    floorCount = other.floorCount;
    /*std::cout << "\n[Character] " << name << " copy-constructed" << std::endl;*/
}

Character& Character::operator=(const Character& other) {
    /*std::cout << "[Character] " << name << " assigned" << std::endl;*/
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        for (int i = 0; i < floorCount; ++i)
            delete floor[i];
        floorCount = 0;
        for (int i = 0; i < other.floorCount; ++i) {
            floor[i] = other.floor[i]->clone();
        }
        floorCount = other.floorCount;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    for (int i = 0; i < floorCount; ++i)
        delete floor[i];
    std::cout << "\n[Character] " << name << " destructed" << std::endl;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m)
		return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            /*std::cout << "[Character] " << name << " equips " << m->getType() << std::endl;*/
            return;
        }
    }
    // inventory full: delete materia
    /*delete m;*/
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) 
		return;
    /*std::cout << "[Character] " << name << " unequips " << inventory[idx]->getType() << std::endl;*/
    if (floorCount < 100) {
        floor[floorCount++] = inventory[idx];
    } else {
        delete inventory[idx];
    }
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!inventory[idx]) {
		std::cout << "Wow, you are doing a nothing! So cool!" << std::endl;
	}
    if (idx < 0 || idx >= 4 || !inventory[idx]) 
		return;
    inventory[idx]->use(target);
}
