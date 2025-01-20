/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:40:17 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/01 19:54:24 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
	static int	seed = 0;
	if (seed == 0)
	{
		srand(time(NULL));
		seed = 1;
	}
	Base* b = NULL;
	int i = rand() % 3;
	if (i == 0)
	{
		b = new A();
		std::cout << "generate A" << std::endl;
	}
	else if (i == 1)
	{
		b = new B();
		std::cout << "generate B" << std::endl;
	}
	else if (i == 2)
	{
		b = new C();
		std::cout << "generate C" << std::endl;
	}
	return (b);
}

void identify(Base* p)
{
	// returns nullptr at bad cast during downcast with pointer
	if (dynamic_cast<A*>(p))
	{
		std::cout << "identify A (by pointer)" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "identify B (by pointer)" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "identify C (by pointer)" << std::endl;
	}
}

void identify(Base& p)
{
	// throws std::bad_cast at bad cast during downcast with reference
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identify A (by reference)" << std::endl;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identify B (by reference)" << std::endl;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identify C (by reference)" << std::endl;
	}
	catch (std::exception&) {}
}
