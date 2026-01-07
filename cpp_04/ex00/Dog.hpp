/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:49:55 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/04 19:41:57 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	~Dog();
	
	void makeSound() const;
	const std::string getType() const;
} ;
