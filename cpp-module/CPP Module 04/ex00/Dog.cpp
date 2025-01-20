/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:51:01 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:37:03 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string	Dog::getType() const
{
	return (_type);
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

Dog&	Dog::operator=(const Dog &d)
{
	std::cout << "Dog: Copy assignation" << std::endl;
	_type = d._type;
	return (*this);
}

Dog::Dog(void)
: Animal()
{
	std::cout << "Dog: Default constructor" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &d)
: Animal()
{
	std::cout << "Dog: Copy constructor" << std::endl;
	_type = d._type;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor" << std::endl;
}
