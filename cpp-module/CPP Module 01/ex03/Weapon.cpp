/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:06:51 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/19 18:38:29 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void		Weapon::setType(std::string type)
{
	std::cout << "*** Weapon type " << _type << "is changed into " << type << std::endl;
	_type = type;
}

std::string	&Weapon::getType()
{
	return (_type);
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "*** Weapon " << _type << " is generated" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "*** Weapon " << _type << " is broken" << std::endl;
}
