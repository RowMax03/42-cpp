/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:32:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/25 15:21:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);
		~Fixed(void);
		Fixed & operator = (const Fixed &fixed);
		bool operator > (const Fixed &fixed2);
		bool operator < (const Fixed &fixed2);
		bool operator >= (const Fixed &fixed2);
		bool operator <= (const Fixed &fixed2);
		bool operator == (const Fixed &fixed2);
		bool operator != (const Fixed &fixed2);
		Fixed operator+ (const Fixed &fixed2);
		Fixed operator- (const Fixed &fixed2);
		Fixed operator* (const Fixed &fixed2);
		Fixed operator/ (const Fixed &fixed2);
		Fixed & operator++ ();
		Fixed & operator-- ();
		Fixed operator++ (int);
		Fixed operator-- (int);
		static Fixed & min(Fixed &fixed1, Fixed &fixed2);
		static Fixed & max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed & min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed & max(const Fixed &fixed1, const Fixed &fixed2);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int	_fixedPointValue;
		const static int _fractionalBits = 8;
};

std::ostream & operator << (std::ostream& output, const Fixed &fixed);

#endif
 