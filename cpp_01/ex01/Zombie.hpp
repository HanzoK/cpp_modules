/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:15:43 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 16:42:17 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie();
	~Zombie() ;
	Zombie(std::string name);


private:
	std::string name;
public:

	void announce(void);
} ;

Zombie* zombieHorde(int N, std::string name);
