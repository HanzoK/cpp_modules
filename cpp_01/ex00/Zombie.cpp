/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:07:42 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/19 15:01:18 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie() {
	std::cout << "*sounds of Zombie being snapped out of existence*" << std::endl << "Zombie " << this->name << " has been utterly annihilated." << std::endl << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl << std::endl;
}
