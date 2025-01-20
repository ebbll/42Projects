/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:03:14 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 17:49:24 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

# define SPAN_SIZE 1000000

int	main(void)
{
	Span	s(SPAN_SIZE);

	std::cout << "Maximum size: " << s.getSize() << std::endl;
	std::cout << "Element count: " << s.getElementCount() << std::endl;

	std::cout << "\nEXCEPTION TEST 01" << std::endl;
	try
	{
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\nEXCEPTION TEST 02" << std::endl;
	try
	{
		s.generateNumbers(SPAN_SIZE + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\nTEST 01" << std::endl;
	s.addNumber(INT_MAX);
	s.addNumber(6);
	s.addNumber(INT_MIN);
	s.addNumber(3);
	s.addNumber(17);
	std::cout << "Element count: " << s.getElementCount() << std::endl;
	s.displaySpan();
	try
	{
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\nTEST 02" << std::endl;
	try
	{
		s.generateNumbers(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Element count: " << s.getElementCount() << std::endl;
	try
	{
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\nTEST 03" << std::endl;
	try
	{
		s.generateNumbers(1000000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Element count: " << s.getElementCount() << std::endl;
	try
	{
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\nEXCEPTION TEST 03" << std::endl;
	try
	{
		s.generateNumbers(SPAN_SIZE);
		s.addNumber(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
