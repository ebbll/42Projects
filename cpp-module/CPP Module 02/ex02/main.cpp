/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:34 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 17:55:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "=============" << std::endl;

	Fixed x;
	Fixed y(2.5f);
	Fixed z(5);

	std::cout << "x : " << x << std::endl;
	std::cout << "y : " << y << std::endl;
	std::cout << "z : " << z << std::endl;

	std::cout << "x > y : " << std::boolalpha << (x > y) << std::endl;
	std::cout << "x < y : " << std::boolalpha << (x < y) << std::endl;
	std::cout << "x >= y : " << std::boolalpha << (x >= y) << std::endl;
	std::cout << "x <= y : " << std::boolalpha << (x <= y) << std::endl;
	std::cout << "x == y : " << std::boolalpha << (x == y) << std::endl;
	std::cout << "x != y : " << std::boolalpha << (x != y) << std::endl;

	std::cout << "y + z = " << y + z << std::endl;
	std::cout << "y - z = " << y - z << std::endl;
	std::cout << "y * z = " << y * z << std::endl;
	std::cout << "y / z = " << y / z << std::endl;
	std::cout << "y / x = " << y / x << std::endl;

	std::cout << "max(y, z) : " << Fixed::max(y, z) << std::endl;
	std::cout << "min(y, z) : " << Fixed::min(y, z) << std::endl;

	return 0;
}
