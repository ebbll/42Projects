/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:31 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 19:12:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Attacking " << target << " failed! (Scavtrap " 
		<< _name << " is already dead)" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "Attackinging " << target << " failed! (lack of energy points)"
		<< std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "[System] ScavTrap " << _name
	<< " is now in Gate keeper mode" << std::endl;
}

/*
	Orthodox canonical form
	1. assignment operator overide
	2. default constructor
	3. copy constructor
	4. destructor
*/
ScavTrap&	ScavTrap::operator=(const ScavTrap &s)
{
	std::cout << "[System] ScavTrap " << s._name << " Has Been Copied!" << std::endl;
	_name = s._name;
	_hitPoints = s._hitPoints;
	_energyPoints = s._energyPoints;
	_attackDamage = s._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = s._maxHP;
	return (*this);
}

ScavTrap::ScavTrap(void)
: ClapTrap()
{
	std::cout << "[System] ScavTrap with no name Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	*(const_cast<unsigned int*>(&_maxHP)) = 100;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "[System] ScavTrap " << _name << " Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	*(const_cast<unsigned int*>(&_maxHP)) = _hitPoints;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	std::cout << "[System] ScavTrap " << s._name << "'s Clone Has Been Created!" << std::endl;
	_name = s._name + "_copy";
	_hitPoints = s._hitPoints;
	_energyPoints = s._energyPoints;
	_attackDamage = s._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = s._maxHP;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[System] Scavtrap " << _name << " Left the Game!" << std::endl;
}
