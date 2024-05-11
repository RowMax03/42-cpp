/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:53:55 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 18:03:15 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

// For containers that have an iterator
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	return (std::find(container.begin(), container.end(), value));
}

// For containers with key-value pairs
template <typename T_key, typename T_value>
typename std::map<T_key, T_value>::iterator easyfind(std::map<T_key, T_value> &container, int value) {
	typename std::map<T_key, T_value>::iterator it = container.begin();
	while (it != container.end()) {
		if (it->second == value)
			return (it);
		it++;
	}
	return (container.end());
}

// For containers with muti key-value pairs
template <typename T_key, typename T_value>
typename std::multimap<T_key, T_value>::iterator easyfind(std::multimap<T_key, T_value> &container, int value) {
	typename std::multimap<T_key, T_value>::iterator it = container.begin();
	while (it != container.end()) {
		if (it->second == value)
			return (it);
		it++;
	}
	return (container.end());
}