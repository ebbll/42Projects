/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:06:55 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/19 18:36:54 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << _name << " attacks with his "
	<< _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << "*** HumanB got a Weapon " << _weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
: _name(name)
{
	std::cout << "*** HumanB " << _name << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "*** HumanB " << _name << " is down" << std::endl;
}
