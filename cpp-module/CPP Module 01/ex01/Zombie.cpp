/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:32:07 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 15:40:36 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
	return (new Zombie(name));
}

void	Zombie::setName(std::string name)
{
	_name = name;
	announce();
}

Zombie::Zombie(std::string name)
{
	_name = name;
	announce();
}

Zombie::Zombie(void)
{
	std::cout << "Zombie horde arising..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is down..." << std::endl;
}
