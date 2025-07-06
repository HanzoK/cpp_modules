/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:40 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:34:58 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

class HumanB {

public:
	HumanB(std::string name);
	~HumanB();

	void attack();
	void setWeapon(Weapon& newWeapon);

private:
	Weapon* nWeapon;
	std::string name;
} ;
