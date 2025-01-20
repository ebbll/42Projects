/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:16 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/26 20:53:35 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "Grrrr...." << std::endl;
}

Animal&	Animal::operator=(const Animal &a)
{
	_type = a._type;
	std::cout << "Animal: Copy assignation" << std::endl;
	return (*this);
}

Animal::Animal(void)
: _type("Animal")
{
	std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal(const Animal &a)
{
	_type = a._type;
	std::cout << "Animal: Copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor" << std::endl;
}
