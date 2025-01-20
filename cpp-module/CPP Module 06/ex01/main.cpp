/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:37:41 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/01 18:44:41 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void)
{
	Data d;
	Data d1(100);

	std::cout << "d  : " << &d << std::endl;
	std::cout << "d1 : " << &d1 << std::endl;

	uintptr_t uip = serialize(&d);
	uintptr_t uip1 = serialize(&d1);

	std::cout << "uintptr_t d  : " << uip << std::endl;
	std::cout << "uintptr_t d1 : " << uip1 << std::endl;

	Data *dp = deserialize(uip);
	Data *dp1 = deserialize(uip1);

	std::cout << "deserialize d  : " << dp << std::endl;
	std::cout << "deserialize d1 : " << dp1 << std::endl;

	std::cout << "uintptr_t d  : " << std::hex << uip << std::endl;
	std::cout << "uintptr_t d1 : " << std::hex << uip1 << std::endl;

	std::cout << "Data d  : " << std::dec << dp->getData() << std::endl;
	std::cout << "Data d1 : " << std::dec << dp1->getData() << std::endl;
}
