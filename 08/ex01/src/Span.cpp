/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:02:50 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 16:29:50 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::SpanFullException::what() const throw() { return ("Trying to add more numbers then Span Size is forbidden!"); }
const char* Span::NoSpanException::what() const throw() { return ("No span to find!"); }

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &other) : _n(other._n) , _v(other._v) {}

Span& Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_n = other._n;
		_v = other._v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	// std::cout << _n << std::endl;
	if (_v.size() == _n)
		throw SpanFullException();
	_v.push_back(n);
}

void Span::addRange(int begin, int end)
{
	if (std::abs(end + 1 - begin) + _v.size() > _n)
		throw SpanFullException();
    for (int i = begin; i <= end; i++)
        _v.push_back(i);
}

unsigned int Span::shortestSpan()
{
	long int shortest_Span = std::numeric_limits<long int>::max();
	if (_v.size() < 2)
		throw NoSpanException();
	std::sort(_v.begin(), _v.end());
	for (size_t i = 0; i < _v.size() - 1; i++)
	{
		if (std::abs(_v[i] - _v[i+1]) < shortest_Span)
			shortest_Span = std::abs(_v[i] - _v[i+1]);
	}
	return (shortest_Span);
}

unsigned int Span::longestSpan()
{
	if (_v.size() < 2)
		throw NoSpanException();
	std::sort(_v.begin(), _v.end());
	return (std::abs(_v.back() - _v.front()));
}