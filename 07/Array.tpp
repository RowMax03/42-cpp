/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:01:10 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 15:44:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::OutOfLimits::OutOfLimits() {throw std::out_of_range("Out of limits");}

Array::Array() : _array(nullptr), _size(0) {}

Array::Array(unsigned int n) : _array(new T[n]), _size(n) {}

Array::Array(Array const &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

Array::~Array()
{
	delete [] _array;
}

Array &Array::operator=(Array const &other)
{
	if (this != &other)
	{
		delete [] _array;
		_array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

T &Array::operator[](unsigned int i)
{
	
}