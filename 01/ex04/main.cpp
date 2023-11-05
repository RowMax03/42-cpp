/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:56:37 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/05 17:08:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char	**argv)
{
	std::string new_file;

	if (argc < 4)
		return (std::cout << "Usage: filename <string to replace> <replacement string>", 1);
	new_file = argv[1];
	new_file.append(".replace");
	std::ifstream input(argv[1]);
	if (!input)
		return (std::cout << "Error: File does not exist or does not have the correct acces rights." << std::endl, 1);
	std::ofstream output(new_file);
	if (!output.is_open())
		return (std::cout << "Error: Opening ouput file" << std::endl, 1);
	std::string line;
	while (std::getline(input, line))
	{
		std::string	replace;
		replace = line;
		size_t	pos;
		while ((pos = replace.find(argv[2])) != std::string::npos)
		{
			replace.erase(pos, strlen(argv[2]));
			replace.insert(pos, argv[3]);
		}
		output << replace << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
