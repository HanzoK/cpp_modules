/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:33:38 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/06 14:58:28 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	virtual ~Cat();

	void makeSound() const;
	const std::string getType() const;
	Brain* getBrain() const;

private:
	Brain* brain;
};
