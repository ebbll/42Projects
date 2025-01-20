/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:16 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:33:09 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "Grrrr...." << std::endl;
}

Animal&	Animal::operator=(const Animal &a)
{
	std::cout << "Animal: Copy assignation" << std::endl;
	_type = a._type;
	return (*this);
}

Animal::Animal(void)
: _type("Animal")
{
	std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal(const Animal &a)
{
	std::cout << "Animal: Copy constructor" << std::endl;
	_type = a._type;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor" << std::endl;
}
