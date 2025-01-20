/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:27:54 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 19:46:44 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	makeItLoud(const char &element)
{
	std::cout << static_cast<char>(std::toupper(element)) << std::endl;
}

void	makeItDouble(const int &element)
{
	std::cout << element * 2 << std::endl;
}

void	makeItPretty(const std::string &element)
{
	std::cout << "***" << element << "***" << std::endl;
}

int	main(void)
{
	char c[5] = { 'a', 'b', 'c', 'd', 'e' };
	int i[6] = { 0, 1, 2, 3, 4, 5 };
	std::string s[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	std::cout << "char iter test" << std::endl;
	iter(c, 5, makeItLoud);

	std::cout << "int iter test" << std::endl;
	iter(i, 6, makeItDouble);

	std::cout << "string iter test" << std::endl;
	iter(s, 7, makeItDouble);

	return (0);
}
