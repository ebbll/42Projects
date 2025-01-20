/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:18 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/26 16:37:38 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "[System] I am DiamondTrap " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &d)
{
	std::cout << "[System] DiamondTrap " << d._name << " Has Been Copied!" << std::endl;
	_name = d._name;
	_hitPoints = d._hitPoints;
	_energyPoints = d._energyPoints;
	_attackDamage = d._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = d._maxHP;
	return (*this);
}

DiamondTrap::DiamondTrap(void)
: _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	std::cout << "[System] DiamondTrap with no name Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	*(const_cast<unsigned int*>(&_maxHP)) = 100;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "[System] DiamondTrap " << _name << " Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	*(const_cast<unsigned int*>(&_maxHP)) = _hitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
: ClapTrap(d), ScavTrap(d), FragTrap(d), _name(d._name)
{
	std::cout << "[System] DiamondTrap " << d._name << "'s Clone Has Been Created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[System] Diamondtrap " << _name << " Left the Game!" << std::endl;
}
