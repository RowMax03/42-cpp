/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:30:36 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:30 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	const_iterator begin() const { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator end() const { return this->c.end(); }
};