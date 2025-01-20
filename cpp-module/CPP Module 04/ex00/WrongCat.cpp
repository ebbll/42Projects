/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:55:20 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:30:58 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

std::string	WrongCat::getType() const
{
	return (_type);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &wc)
{
	std::cout << "WrongCat: Copy assignation" << std::endl;
	_type = wc._type;
	return (*this);
}

WrongCat::WrongCat(void)
: WrongAnimal()
{
	std::cout << "WrongCat: Default constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wc)
: WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor" << std::endl;
	_type = wc.getType();
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor" << std::endl;
}
