/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:12:20 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/11 13:47:11 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point A( 0.0f,  0.0f);
    Point B(10.0f,  0.0f);
    Point C( 0.0f, 10.0f);

    Point inside(1.0f, 1.0f);
    Point edge(5.0f, 0.0f);
    Point vertex(0.0f, 0.0f);
    Point outside(10.0f, 10.0f);

    std::cout << "inside:  " << (bsp(A,B,C,inside) ? "true" : "false")  << " (expected true)\n";
    std::cout << "edge:    " << (bsp(A,B,C,edge) ? "true" : "false")    << " (expected false)\n";
    std::cout << "vertex:  " << (bsp(A,B,C,vertex) ? "true" : "false")  << " (expected false)\n";
    std::cout << "outside: " << (bsp(A,B,C,outside) ? "true" : "false") << " (expected false)\n";

    return 0;
}
