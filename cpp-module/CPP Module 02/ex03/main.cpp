/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:54 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 17:11:28 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	const Point	a(0, 0);
	const Point	b(4, 6);
	const Point	c(9, 3);

	const Point	point1(0, 0);
	const Point	point2(4.5, 1.5);
	const Point	point3(-1, -1);
	const Point	point4(7.0, 3.5);

	// point가 A점
	std::cout << "[TEST01]: " << std::boolalpha << bsp(a, b, c, point1) << std::endl;
	// point가 AC 위에 있음
	std::cout << "[TEST02]: " << std::boolalpha << bsp(a, b, c, point2) << std::endl;
	// point가 삼각형 밖에 있음
	std::cout << "[TEST03]: " << std::boolalpha << bsp(a, b, c, point3) << std::endl;
	// point가 삼각형 안에 있음
	std::cout << "[TEST04]: " << std::boolalpha << bsp(a, b, c, point4) << std::endl;

	return (0);
}
