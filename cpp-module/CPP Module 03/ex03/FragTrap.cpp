/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:24 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 22:14:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Attacking " << target << " failed! (Fragtrap " 
		<< _name << " is already dead)" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "Attacking " << target << " failed! (lack of energy points)"
		<< std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[System] FragTrap " << _name
	<< " requests positive high fives" << std::endl;
}

/*
	Orthodox canonical form
	1. assignment operator overide
	2. default constructor
	3. copy constructor
	4. destructor
*/
FragTrap&	FragTrap::operator=(const FragTrap &f)
{
	std::cout << "[System] FragTrap " << f._name << " Has Been Copied!" << std::endl;
	_name = f._name;
	_hitPoints = f._hitPoints;
	_energyPoints = f._energyPoints;
	_attackDamage = f._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = f._maxHP;
	return (*this);
}

FragTrap::FragTrap(void)
: ClapTrap()
{
	std::cout << "[System] FragTrap with no name Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	*(const_cast<unsigned int*>(&_maxHP)) = 100;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	std::cout << "[System] FragTrap " << _name << " Joined the Game!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	*(const_cast<unsigned int*>(&_maxHP)) = _hitPoints;
}

FragTrap::FragTrap(const FragTrap &f)
{
	std::cout << "[System] FragTrap " << f._name << "'s Clone Has Been Created!" << std::endl;
	_name = f._name + "_copy";
	_hitPoints = f._hitPoints;
	_energyPoints = f._energyPoints;
	_attackDamage = f._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = f._maxHP;
}

FragTrap::~FragTrap()
{
	std::cout << "[System] Fragtrap " << _name << " Left the Game!" << std::endl;
}
