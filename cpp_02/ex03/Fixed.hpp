/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:14:05 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/11 13:21:18 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	bool operator>(const Fixed& calc) const;
	bool operator<(const Fixed& calc) const;
	bool operator>=(const Fixed& calc) const;
	bool operator<=(const Fixed& calc) const;
	bool operator==(const Fixed& calc) const;
	bool operator!=(const Fixed& calc) const;

	Fixed operator+(const Fixed& calc);
	Fixed operator-(const Fixed& calc);
	Fixed operator*(const Fixed& calc);
	Fixed operator/(const Fixed& calc);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(Fixed const & a, Fixed const & b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _rawBits;
	static const int _fractBits = 8;
} ;

std::ostream & operator<<(std::ostream & os, Fixed const & fnum);

