/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:30 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:46:47 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void attack();

private:
	std::string name;
	Weapon& nWeapon2;
} ;
