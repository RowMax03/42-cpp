/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:01:10 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 15:32:21 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
const char* Array<T>::OutOfLimits::what() const throw() {return ("Out of limits");}

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
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

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw Array::OutOfLimits();
	return _array[i];
}