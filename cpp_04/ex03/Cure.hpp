/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:40:08 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 15:38:42 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& copy);
	Cure &operator=(const Cure& copy);
	virtual ~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};
