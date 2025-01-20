/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:55:25 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:33:48 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal: Grrrr...." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal: Copy assignation" << std::endl;
	_type = wa._type;
	return (*this);
}

WrongAnimal::WrongAnimal(void)
: _type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	std::cout << "WrongAnimal: Copy constructor" << std::endl;
	_type = wa.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor" << std::endl;
}