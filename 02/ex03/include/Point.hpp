/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:56:10 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:37 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);
		Point & operator = (const Point &point);
		Fixed getX(void) const;
		Fixed getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif