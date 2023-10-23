/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:32:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/23 21:03:35 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
//#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = num << this->_fractionalBits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

std::ostream &operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

bool operator > (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits());
}

bool operator < (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits());
}

bool operator >= (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() >= fixed2.getRawBits());
}

bool operator <= (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() <= fixed2.getRawBits());
}

bool operator == (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() == fixed2.getRawBits());
}

bool operator != (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() != fixed2.getRawBits());
}

Fixed &operator + (Fixed &fixed1, Fixed &fixed2)
{
	Fixed &fix = fixed1;
	fix._fixedPointValue = fixed1.getRawBits() + fixed2.getRawBits();
	return (fix);
}

Fixed &operator - (Fixed &fixed1, Fixed &fixed2)
{
	Fixed &fix = fixed1;
	fix._fixedPointValue = fixed1.getRawBits() - fixed2.getRawBits();
	return (fix);
}

Fixed & operator ++ (Fixed &fixed)
{
	fixed._fixedPointValue++;
	return (fixed);
}

Fixed & operator -- (Fixed &fixed)
{
	fixed._fixedPointValue--;
	return (fixed);
}

Fixed operator ++ (Fixed &fixed, int)
{
	Fixed fix = fixed;
	fix._fixedPointValue++;
	return (fix);
}

Fixed operator -- (Fixed &fixed, int)
{
	Fixed fix = fixed;
	fix._fixedPointValue--;
	return (fix);
}

Fixed Fixed::operator* (const Fixed &fixed2)
{
	Fixed fix = fixed2;
	fix._fixedPointValue = (this->getRawBits() * fixed2.getRawBits()) >> fix._fractionalBits;
	return (fix);
}

// Fixed &operator* (Fixed &fixed1, Fixed &fixed2)
// {
// 	Fixed fix = fixed1;
//     return (fixed1.getRawBits() * fixed2.getRawBits()) >> fix._fractionalBits;
// }

Fixed Fixed::operator / (const Fixed &fixed2)
{
	Fixed fix = fixed2;
	fix._fixedPointValue = (this->getRawBits() << fix._fractionalBits) / fixed2.getRawBits();
	return (fix);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed & Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed & Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

//std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
//{
//	output << fixed.toFloat();
//	return output;
//}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}
