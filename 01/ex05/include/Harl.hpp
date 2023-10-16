/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:46:34 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif