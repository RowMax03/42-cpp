/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:55:51 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 16:13:16 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span();
	void addNumber(int n);
	void addRange(int begin, int end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class SpanFullException : public std::exception
	{
		const char *what() const throw();
	};
	class NoSpanException : public std::exception
	{
		const char *what() const throw();
	};
private:
	unsigned int _n;
	std::vector<int> _v;
};
