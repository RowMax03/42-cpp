/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:55:06 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/03 16:30:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap & operator=(DiamondTrap const & src);
		using ScavTrap::attack;
		void whoAmI();
	private:
		std::string _name;
};

#endif