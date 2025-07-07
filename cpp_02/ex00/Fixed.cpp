/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:41:13 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/07 15:33:20 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Calling constructur and setting default value of rawBits to 0
Fixed::Fixed()
    : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//calls copy constructor and assigns copy of passed class into current class
Fixed::Fixed(Fixed const & copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

//copy assignment operator
//if current class is not the same as the passed copy, then copy rawBits from copy to current class
Fixed & Fixed::operator=(Fixed const & copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->_rawBits = copy.getRawBits();
    return *this;
}

//Standard destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//getter function for rawBits value
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

//setter function for rawBits value
void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}
