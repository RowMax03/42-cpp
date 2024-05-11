/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:30:39 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 18:33:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <iterator>

int main2();

int main()
{
std::list<int> lstack;
lstack.push_back(5);
lstack.push_back(17);
std::cout << lstack.back() << std::endl;
lstack.pop_back();
std::cout << lstack.size() << std::endl;
lstack.push_back(3);
lstack.push_back(5);
lstack.push_back(737);
lstack.push_back(0);
std::list<int>::iterator it = lstack.begin();
std::list<int>::iterator ite = lstack.end();
++it;
--it;
while (it != ite)
{
	std::cout << *it << std::endl;
	++it;
}
std::cout << "lstack size: " << lstack.size() << std::endl;
std::list<int> s(lstack);
std::cout << "Copy list size: " << s.size() << std::endl;
std::cout << "-^--list impl--^-" << std::endl;
std::cout << "-----------------" << std::endl;
std::cout << "-v-mutantstack-v-" << std::endl;
return main2();
}

int main2()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
	std::cout << *it << std::endl;
	++it;
}
std::stack<int> s(mstack);
s.push(42);
std::cout << "---- swap tests ----" << std::endl;
std::cout << "mstack Size: " << mstack.size() << std::endl;
std::cout << "Copy Stack Size: " << s.size() << std::endl;

mstack.swap(s);
it = mstack.begin();
ite = mstack.end();
while (it != ite)
{
	std::cout << *it << std::endl;
	++it;
}
// it = s.begin();
// ite = s.end();

return 0;
}
