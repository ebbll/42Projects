/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:57:03 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 15:04:53 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	Bureaucrat senior("senior", 1);
	Bureaucrat junior("junior", 150);

	Form	x("Resume", 150, 150);
	Form	y("Resignation", 10, 10);

	std::cout << std::endl;
	junior.signForm(y);

	std::cout << std::endl;
	std::cout << y << std::endl;

	std::cout << std::endl;
	senior.signForm(x);
	senior.signForm(y);

	std::cout << std::endl;
	std::cout << x << std::endl;
	std::cout << std::endl;
	std::cout << y << std::endl;

	std::cout << std::endl;

	return (0);
}