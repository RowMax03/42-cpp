/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:33:08 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 18:11:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::map<int, int> m;
	m[42] = 3;
	v.push_back(42);
	try
	{	
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}