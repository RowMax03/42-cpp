/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 18:22:13 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
private:
	void makePairs(std::vector<int> const &input);
	std::vector<std::pair<int, int>> _data;
};