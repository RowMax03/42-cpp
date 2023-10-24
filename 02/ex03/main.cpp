/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:49 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/24 18:40:35 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	Point point(2, 2);
	std::cout << "Triangle consisting of Points:" << std::endl;
	std::cout << "a: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "b: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "c: " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "Point to check: " << point.getX() << ", " << point.getY() << std::endl;
	std::cout << "So tell me dear Computer, are the rumors true that this Point lives in the Land of triangle?" << std::endl;
	std::cout << (bsp(a, b, c, point) ? "Yes, the rumors are true" : "No, the rumors are false") << std::endl;
	return (0);
}
