/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:37:17 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/06 15:38:23 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	virtual ~Ice();


	AMateria *clone() const;
	void use(ICharacter &target);
};
