/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:17:53 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 20:56:41 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;

class AMateria {
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria&);
	virtual ~AMateria();

	std::string const &getType() const; // return materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	const std::string type;
};
