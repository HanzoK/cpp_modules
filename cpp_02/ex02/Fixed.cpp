/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:18 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/09 17:19:30 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//----------------constructors & destructor-------------------*/

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed& copy) {
    _rawBits = copy._rawBits;
}

Fixed::Fixed(const int num) {
    _rawBits = num << _fractBits;
}

Fixed::Fixed(const float fnum) {
    _rawBits = (int)(roundf(fnum * (1 << _fractBits)));
}

Fixed::~Fixed() {
}

//---------------------assignment operator-------------------*/

Fixed& Fixed::operator=(const Fixed& copy) {
    if (this != &copy)
        _rawBits = copy._rawBits;
    return *this;
}

//-----------------------comparison operators-------------*/

bool Fixed::operator>(const Fixed& calc)  const {
	return _rawBits > calc._rawBits;
}

bool Fixed::operator<(const Fixed& calc)  const {
	return _rawBits < calc._rawBits;
}

bool Fixed::operator>=(const Fixed& calc) const {
	return _rawBits >= calc._rawBits;
}

bool Fixed::operator<=(const Fixed& calc) const {
	return _rawBits <= calc._rawBits;
}

bool Fixed::operator==(const Fixed& calc) const {
	return _rawBits == calc._rawBits;
}

bool Fixed::operator!=(const Fixed& calc) const {
	return _rawBits != calc._rawBits;
}

/*------------------arithmetic operators-------------------*/

Fixed Fixed::operator+(const Fixed& calc) {
    Fixed tmp;
    tmp._rawBits = _rawBits + calc._rawBits;
    return tmp;
}

Fixed Fixed::operator-(const Fixed& calc) {
    Fixed tmp;
    tmp._rawBits = _rawBits - calc._rawBits;
    return tmp;
}

Fixed Fixed::operator*(const Fixed& calc) {
    Fixed tmp;
    long multi = (long)_rawBits * calc._rawBits;
    tmp._rawBits = (int)(multi >> _fractBits);
    return tmp;
}

Fixed Fixed::operator/(const Fixed& calc) {
    Fixed tmp;
    long div = (long)_rawBits << _fractBits;
	std::cout << "div: " << div << std::endl;
	if (!calc._rawBits) {
		std::cout << "yo wtf?" << std::endl;
		exit(69);
	}
    tmp._rawBits = (int)(div / calc._rawBits);
	std::cout << "wtf?" << std::endl;
    return tmp;
}

/*---------increment & decrement operators--------------*/

Fixed& Fixed::operator++() {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);
    ++_rawBits;
    return old;
}

Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    --_rawBits;
    return old;
}

//--------------getter & setter-------------------*/

int Fixed::getRawBits() const { 
	return _rawBits; 
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw; 
}

/*----------------float/int converters------------------*/

float Fixed::toFloat() const {
    return (float)(_rawBits) / (1 << _fractBits);
}

int Fixed::toInt() const {
    return _rawBits >> _fractBits;
}

/*------------------min & max functions----------------*/

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

//-----------stream insertion operator----------------------

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
