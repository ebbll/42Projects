/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:06:53 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/19 18:36:49 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << _name << " attacks with his "
	<< _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _weapon(weapon)
{
	std::cout << "*** HumanA " << _name << " created"
	<< " and he carries Weapon " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "*** HumanA " << _name << " is down" << std::endl;
}
