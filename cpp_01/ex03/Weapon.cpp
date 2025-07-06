/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:24 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:49:27 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon() {
}

void Weapon::setType(const std::string& new_type) {
	this->type = new_type;
}

const std::string& Weapon::getType() const {
	return this->type;
}

