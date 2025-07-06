/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:11:31 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/19 14:51:01 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {

public: 
	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);

private:
	std::string name;

} ;

Zombie* newZombie(std::string name);
void randomChump(std::string name);
