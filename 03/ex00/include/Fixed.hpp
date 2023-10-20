/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:32:21 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/20 11:33:23 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	~Fixed(void);
	Fixed & operator = (const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int	_fixedPointValue;
	const static int _fractionalBits = 8;
};

#endif
