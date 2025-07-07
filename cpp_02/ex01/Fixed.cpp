/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:36:55 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/07 19:15:34 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num) {
	this->_rawBits = num << _fractBits;
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float fnum) {
	this->_rawBits = fnum * (1 << _fractBits);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& copy) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(Fixed const& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const{
	return (this->_rawBits >> this->_fractBits);
}

float Fixed::toFloat(void) const{
	return ((float)this->_rawBits / (1 << _fractBits));
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

std::ostream & operator<<(std::ostream & os, Fixed const & fnum) {
	return (os << fnum.toFloat());
}
