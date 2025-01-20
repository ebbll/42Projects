/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:01:37 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 16:21:13 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int>	intv;
	std::list<int>		intl;
	std::deque<int>		intd;

	int	inValue = 5;
	int	outValue = -100;

	for (int i = 0; i < 10; ++i)
	{
		intv.push_back(i);
		intl.push_back(i);
		intd.push_back(i);
	}

	std::cout << "VECTOR TEST" << std::endl;
	try
	{
		std::cout << *std::find(intv.begin(), intv.end(), inValue) << std::endl;
		std::cout << *easyfind(intv, inValue) << std::endl;

		std::cout << *std::find(intv.begin(), intv.end(), outValue) << std::endl;
		std::cout << *easyfind(intv, outValue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nLIST TEST" << std::endl;
	try
	{
		std::cout << *std::find(intl.begin(), intl.end(), inValue) << std::endl;
		std::cout << *easyfind(intl, inValue) << std::endl;

		std::cout << *std::find(intl.begin(), intl.end(), outValue) << std::endl;
		std::cout << *easyfind(intl, outValue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nDEQUE TEST" << std::endl;
	try
	{
		std::cout << *std::find(intd.begin(), intd.end(), inValue) << std::endl;
		std::cout << *easyfind(intd, inValue) << std::endl;

		std::cout << *std::find(intd.begin(), intd.end(), outValue) << std::endl;
		std::cout << *easyfind(intd, outValue) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
