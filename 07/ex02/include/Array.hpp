/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:54:16 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 15:27:41 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();
		Array &operator=(Array const &other);
		T &operator[](unsigned int i);
		unsigned int size() const;
	class OutOfLimits : public std::exception
	{
		const char *what() const throw();
	};
};

#include "../src/Array.tpp"