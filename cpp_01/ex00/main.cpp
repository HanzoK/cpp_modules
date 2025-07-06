/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:10:23 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/19 15:10:46 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	randomChump("Bob");
	Zombie* Overlord = newZombie("Jeff");
	Overlord->announce();
	delete Overlord;
}
