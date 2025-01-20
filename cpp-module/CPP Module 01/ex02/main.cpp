/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:50:15 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/19 18:35:03 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	original = "HI THIS IS BRAIN";
	std::string	*stringPTR = &original;
	std::string	&stringREF = original;

	std::cout << "Address of the string: " << static_cast<void *>(&original) << std::endl;
	std::cout << "Address of the string using pointer: " << stringPTR << std::endl;
	std::cout << "Address of the pointer: " << static_cast<void *>(&stringPTR) << std::endl;
	std::cout << "Address of the string using reference: " << static_cast<void *>(&stringREF) << std::endl;
	std::cout << "String from pointer: " << *stringPTR << std::endl;
	std::cout << "String from reference: " << stringREF << std::endl;
	return (0);
}
