/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:34:41 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/01 19:00:12 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class	contact{
	public:
		contact(void);
		~contact(void);
		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_number(std::string number);
		void	set_nickname(std::string nickname);
		void	set_dark_secret(std::string darkest_secret);
		std::string	get_contact(void);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
};

#endif