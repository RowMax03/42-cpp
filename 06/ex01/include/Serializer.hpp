/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:13:35 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 17:28:50 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <cstdint>
#include <iostream>


struct Data
{
	int n;
	double d;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};