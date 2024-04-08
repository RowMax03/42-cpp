/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:03:07 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 19:23:56 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> // rand

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		throw std::exception();
}

void identify(Base& p)
{
	try {
		identify(&p);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *p = generate();
	Base &r = *p;
	Base *c = generate();
	Base q;
	identify(r);
	identify(p);
	identify(*p);
	identify(c);
	identify(q);
	delete p;
	delete c;
	return 0;
}