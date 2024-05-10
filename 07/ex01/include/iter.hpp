/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:31:40 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 14:47:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T *array, int length, void (*func)(T &)) {
	for (int i = 0; i < length; i++) {
		func(array[i]);
	}
}

template <typename T>
void print(T &x) {
	std::cout << x << ", ";
}

template <typename T>
void increment(T &x) {
	x++;
}