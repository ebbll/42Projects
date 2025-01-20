/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:48:48 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 13:04:49 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) :_name(name)
{
	announce();
}

Zombie::Zombie(void)
{
	std::cout << "I don't have name, therefore I don't exist..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << "> is decaying..." << std::endl;
}
