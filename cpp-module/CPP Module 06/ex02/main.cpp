/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:39:48 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 14:45:21 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base	*p = generate(); // upcast
	identify(p);
	// std::cout << dynamic_cast<A*>(p) << std::endl;
	// std::cout << dynamic_cast<B*>(p) << std::endl;
	// std::cout << dynamic_cast<C*>(p) << std::endl;

	identify(*p);
	// A	tempA = dynamic_cast<A&>(*p);
	// std::cout << &tempA << std::endl;
	// B	tempB = dynamic_cast<B&>(*p);
	// std::cout << &tempA << std::endl;
	// C	tempC = dynamic_cast<C&>(*p);
	// std::cout << &tempA << std::endl;

	// // test with pointer
	// Base	*test1 = new A();
	// B	*res = static_cast<B*>(test1);
	// std::cout << res << std::endl;
	// Base	*ret = static_cast<Base*>(res);
	// std::cout << ret << std::endl;

	// // test with reference
	// Base	*test2 = new C();
	// B	res = static_cast<B&>(*test2);
	// std::cout << &res << std::endl;

	delete p;
	// delete test1;
	// delete test2;
	return (0);
}
