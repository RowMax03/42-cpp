/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:26:54 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/01 19:36:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.h"

class phonebook {
	public:
		phonebook(void);
		~phonebook(void);
		void	add(void);
		void	search(void);
	private:
		int		contact_index;
		int		contact_count;
		contact	contacts[8];
};

#endif