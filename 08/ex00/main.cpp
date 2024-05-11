/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:33:08 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 14:50:58 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

int main()
{
	// Vector
	std::cout << "--- Vector ---" << std::endl;
	std::vector<int> v;
	v.push_back(42);
	int search_v = 42;
	std::vector<int>::iterator it = easyfind(v, search_v);
	if (it == v.end())
		std::cout << "Did not find "<< search_v << std::endl;
	else
		std::cout << "Found: " << *it << std::endl;

	// List
	std::cout << "--- List ---" << std::endl;
	std::list<int> l;
	l.push_back(33);
	int search_l = 33;
	std::list<int>::iterator it1 = easyfind(l, search_l);
	if (it1 == l.end())
		std::cout << "Did not find "<< search_l << std::endl;
	else
		std::cout << "Found: " << *it1 << std::endl;
	
	// Deque
	std::cout << "--- Deque ---" << std::endl;
	std::deque<int> d;
	d.push_back(44);
	int search_d = 44;
	std::deque<int>::iterator it3 = easyfind(d, search_d);
	if (it3 == d.end())
		std::cout << "Did not find "<< search_d << std::endl;
	else
		std::cout << "Found: " << *it3 << std::endl;
	
	// Map
	std::cout << "--- Map ---" << std::endl;
	std::map<int, int> m;
	m[42] = 3;
	int search_m = 3;
	std::map<int, int>::iterator it2 = easyfind(m, search_m);
	if (it2 == m.end())
		std::cout << "Did not find "<< search_m << std::endl;
	else
		std::cout << "Found: "<< it2->second << " for key: " << it2->first << std::endl;

	// Multimap
	std::cout << "--- Multi map ---" << std::endl;
	std::multimap<int, int> mm;
	mm.insert(std::pair<int, int>(21, 44));
	int search_mm = 44;
	std::multimap<int, int>::iterator it4 = easyfind(mm, search_mm);
	if (it4 == mm.end())
		std::cout << "Did not find "<< search_mm << std::endl;
	else
		std::cout << "Found: "<< it4->second << " for key: " << it4->first << std::endl;

	// Multi Set
	std::cout << "--- Multi Set  ---" << std::endl;
	std::multiset<int> ms;
	for (int i = 0; i < 10; i++)
		ms.insert(i);
	int search_ms = 42;
	std::multiset<int>::iterator it5 = easyfind(ms, search_ms);
	if (it5 == ms.end())
		std::cout << "Did not find "<< search_ms << std::endl;
	else
		std::cout << "Found: " << *it5 << std::endl;
}