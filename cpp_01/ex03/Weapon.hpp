/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:05:20 by hanjkim           #+#    #+#             */
/*   Updated: 2025/06/20 18:03:22 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon {
public:

	Weapon(std::string type);
	~Weapon();

	const std::string& getType() const;
	void setType(const std::string& new_type) ;

private:
	std::string type;
} ;
