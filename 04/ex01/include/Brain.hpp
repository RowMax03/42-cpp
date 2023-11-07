/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:02:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 01:13:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		Brain &operator=(Brain const &rhs);
		virtual ~Brain();
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
	private:
		std::string _ideas[100];
};