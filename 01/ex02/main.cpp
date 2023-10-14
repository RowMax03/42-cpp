/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:04:13 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/14 22:14:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	str_ptr = &str;
	std::string&	str_ref = str;
	std::cout << "Address of string: " << &str << std::endl;
	std::cout << "Address of pointer: " << str_ptr << std::endl;
	std::cout << "Address of reference: " << &str_ref << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "Pointer: " << *str_ptr << std::endl;
	std::cout << "Reference: " << str_ref << std::endl;
	return (0);
}