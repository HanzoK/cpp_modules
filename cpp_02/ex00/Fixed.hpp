/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:41:18 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/07 15:33:22 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {

public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int                 _rawBits;
	static const int    _fractionalBits = 8;
} ;
