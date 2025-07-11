/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:12:53 by hanjkim           #+#    #+#             */
/*   Updated: 2025/07/11 13:42:32 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// helper: find out area of triangle ABC via cross-product-formula / 2
static Fixed area(const Point& A, const Point& B, const Point& C) {
    // Formula used: ((Bx - Ax)*(Cy - Ay) - (By - Ay)*(Cx - Ax)) / 2
    Fixed x1 = B.getX() - A.getX();
    Fixed y1 = B.getY() - A.getY();
    Fixed x2 = C.getX() - A.getX();
    Fixed y2 = C.getY() - A.getY();
    Fixed cross = (x1 * y2) - (y1 * x2);
    if (cross < Fixed(0))
        cross = Fixed(0) - cross;
    return cross / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A  = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    // point strictly inside if A1 + A2 + A3 == A and none zero
    if ((A1 + A2 + A3) == A
        && A1 != Fixed(0)
        && A2 != Fixed(0)
        && A3 != Fixed(0))
        return true;
    return false;
}
