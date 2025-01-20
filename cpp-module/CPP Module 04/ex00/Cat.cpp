/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:48 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:36:39 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

std::string	Cat::getType() const
{
	return (_type);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Cat&	Cat::operator=(const Cat &c)
{
	std::cout << "Cat: Copy assignation" << std::endl;
	_type = c._type;
	return (*this);
}

Cat::Cat(void)
: Animal()
{
	std::cout << "Cat: Default constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &c)
: Animal()
{
	std::cout << "Cat: Copy constructor" << std::endl;
	_type = c._type;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor" << std::endl;
}
