/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:12:05 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed	calc_area(Point const a, Point const b, Point const c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = calc_area(a, b, c);
	Fixed area1 = calc_area(point, b, c);
	Fixed area2 = calc_area(a, point, c);
	Fixed area3 = calc_area(a, b, point);
	return (area == area1 + area2 + area3);
}