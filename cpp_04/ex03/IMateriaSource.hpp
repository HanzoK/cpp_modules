/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:58:02 by hanjkim           #+#    #+#             */
/*   Updated: 2025/08/16 18:53:18 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource();

	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
	/*virtual void printMateria() const = 0; // for debugging*/
};
