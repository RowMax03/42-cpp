/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:32:19 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/23 13:48:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
//#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = num << this->_fractionalBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

std::ostream &operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

bool &operator > (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() > fixed2.getRawBits());
}

bool &operator < (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() < fixed2.getRawBits());
}

bool &operator >= (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() >= fixed2.getRawBits());
}

bool &operator <= (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() <= fixed2.getRawBits());
}

bool &operator == (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() == fixed2.getRawBits());
}

bool &operator != (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() != fixed2.getRawBits());
}

Fixed &operator + (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() + fixed2.getRawBits());
}

Fixed &operator - (const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.getRawBits() - fixed2.getRawBits());
}

Fixed &operator * (const Fixed &fixed1, const Fixed &fixed2)
{
	
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
