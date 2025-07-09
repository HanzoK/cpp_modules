/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:28 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/09 16:50:20 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*int main(void) {*/
/*	Fixed a;*/
/*	Fixed const b(Fixed(5.05f)*Fixed(2));*/
/**/
/*	std::cout << a << std::endl;*/
/*	std::cout << ++a << std::endl;*/
/*	std::cout << a << std::endl;*/
/*	std::cout << a++ << std::endl;*/
/*	std::cout << a << std::endl;*/
/**/
/*	std::cout << b << std::endl;*/
/**/
/*	std::cout << Fixed::max(a, b) << std::endl;*/
/**/
/*	return 0;*/
/*}*/

static void testArithmetic() {
    std::cout << "-- Arithmetic Operators --\n";
    Fixed a(0);
    Fixed b(3.5f);

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";   // 5.5
    std::cout << "a - b = " << (a - b) << "\n";   // -1.5
    std::cout << "a * b = " << (a * b) << "\n";   // 7.0
    std::cout << "b / a = " << (b / a) << "\n";   // 1.75
    std::cout << "\n";
}

static void testComparisons() {
    std::cout << "-- Comparison Operators --\n";
    Fixed x(2);
    Fixed y(2);
    Fixed z(5);

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
    std::cout << "x == y: " << (x == y) << "\n";
    std::cout << "x != z: " << (x != z) << "\n";
    std::cout << "x < z:  " << (x <  z) << "\n";
    std::cout << "x <= y: " << (x <= y) << "\n";
    std::cout << "z >  y: " << (z >  y) << "\n";
    std::cout << "z >= x: " << (z >= x) << "\n";
    std::cout << "\n";
}

static void testIncrementDecrement() {
    std::cout << "-- Increment / Decrement --\n";
    Fixed a;

    std::cout << "initial a: " << a << "\n";

    std::cout << "pre-increment ++a: " << ++a << "\n";
    std::cout << "      value of a:   " << a  << "\n";

    std::cout << "post-increment a++: " << a++ << "\n";
    std::cout << "      value of a:   " << a   << "\n\n";

    std::cout << "pre-decrement --a: " << --a << "\n";
    std::cout << "      value of a:   " << a  << "\n";

    std::cout << "post-decrement a--: " << a-- << "\n";
    std::cout << "      value of a:   " << a   << "\n\n";
}

static void testMinMax() {
    std::cout << "-- min / max Static Methods --\n";
    Fixed a( 1.25f );
    Fixed b( 2.75f );
    const Fixed c( 1.25f );
    const Fixed d( 0.75f );

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min(a,b) = " << Fixed::min( a, b ) << "\n";
    std::cout << "max(a,b) = " << Fixed::max( a, b ) << "\n\n";

    std::cout << "c = " << c << ", d = " << d << "  (const overloads)\n";
    std::cout << "min(c,d) = " << Fixed::min( c, d ) << "\n";
    std::cout << "max(c,d) = " << Fixed::max( c, d ) << "\n\n";
}

int main() {
    std::cout << "\n===== Fixed-point Class Full Test =====\n\n";
    testArithmetic();
    testComparisons();
    testIncrementDecrement();
    testMinMax();
    std::cout << "===== End of Tests =====\n";
    return 0;
}
