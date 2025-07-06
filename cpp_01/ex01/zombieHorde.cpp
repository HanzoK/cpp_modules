/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:15:33 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/19 17:01:31 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	for (int i = N; i > 0; i--) {
		horde[i - 1] = Zombie(name);
		horde[i - 1].announce();
	}
	return horde; 
}
