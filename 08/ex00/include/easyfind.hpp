/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:53:55 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 18:04:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Helper struct to check for find member function
template <typename T>
struct has_find
{
private:
	typedef char yes[1];
	typedef char no[2];

	template <typename C>
	static yes& test( typeof(&C::find) ) ;

	template <typename C>
	static no& test(...);

public:
	enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};

// Functor to compare the first member of a pair with a given value
struct CompareFirst
{
	int value;
	CompareFirst(int val) : value(val) {}
	bool operator()(const std::pair<const int, int>& pair)
	{
		return pair.first == value;
	}
};

// Base template for easyfind
template <typename T, bool hasFind>
struct easyfind_impl
{
	static typename T::iterator find(T &container, int value)
	{
		CompareFirst comp(value);
		typename T::iterator it = std::find_if(container.begin(), container.end(), comp);
		if (it == container.end())
		{
			throw std::exception();
		}
		return it;
	}
};

// Specialization for containers with a find member function
template <typename T>
struct easyfind_impl<T, true>
{
	static typename T::iterator find(T &container, int value)
	{
		typename T::iterator it = container.find(value);
		if (it == container.end())
		{
			throw std::exception();
		}
		return it;
	}
};

// The actual easyfind function that delegates to the correct implementation
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	return easyfind_impl<T, has_find<T>::value>::find(container, value);
}