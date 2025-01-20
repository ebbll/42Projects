/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:38:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 19:49:13 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
	Action 1. Attack
*/
void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "Attacking " << target << " failed! (Claptrap " 
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
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
}

/*
	Action 2. Damage taken
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " is already dead" << std::endl;
		return ;
	}
	if (_hitPoints > amount)
	{
		_hitPoints -= amount;
		std::cout << _name << " has "
		<< _hitPoints << " hit points left!" << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << _name << " died at this moment!" << std::endl;
	}
}

/*
	Action 3. Repair
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "Reparing " << _name
		<< " failed! (already dead)" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "Reparing " << _name
		<< " failed! (lack of energy points)" << std::endl;
		return ;
	}
	if (_hitPoints == _maxHP)
	{
		std::cout << "Reparing " << _name
		<< " failed! (HP already full)" << std::endl;
		return ;
	}
	--_energyPoints;
	if (_hitPoints + amount < _maxHP)
	{
		_hitPoints += amount;
		std::cout << _name
		<< " has been repaired " << amount << " points! (" 
		<< _hitPoints << " hit points left)" << std::endl;
	}
	else
	{
		_hitPoints = _maxHP;
		std::cout << _name
		<< " fully recovered! ("
		<< _hitPoints << " hit points left)" << std::endl;
	}
	
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}

void	ClapTrap::displayStatus(void)
{
	std::cout << "[System] Status of " << _name << std::endl;
	std::cout << std::setw(15) << "STATUS: ";
	if (_hitPoints == 0)
		std::cout << "DEAD / ";
	else
		std::cout << "ALIVE / ";
	if (_energyPoints == 0)
		std::cout << "EXHAUSTED" << std::endl;
	else
		std::cout << "POWERED" << std::endl;
	std::cout << std::setw(15) << "HP: " << _hitPoints << std::endl;
	std::cout << std::setw(15) << "MAX HP: " << _maxHP << std::endl;
	std::cout << std::setw(15) << "ENERGY POINTS: " << _energyPoints << std::endl;
	std::cout << std::setw(15) << "ATTACK DAMAGE: " << _attackDamage << std::endl;
}

/*
	Orthodox canonical form
	1. assignment operator overide
	2. default constructor
	3. copy constructor
	4. destructor
*/
ClapTrap&	ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << "[System] ClapTrap " << c._name << " Has Been Copied!" << std::endl;
	_name = c._name;
	_hitPoints= c._hitPoints;
	_energyPoints = c._energyPoints;
	_attackDamage = c._attackDamage;
	*(const_cast<unsigned int*>(&_maxHP)) = c._maxHP;
	return	(*this);
}

ClapTrap::ClapTrap(void)
: _name(DFLNAME), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHP(10)
{
	std::cout << "[System] ClapTrap with no name Joined the Game!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHP(10)
{
	std::cout << "[System] ClapTrap " << _name << " Joined the Game!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
: _name(c._name + "_copy"), _hitPoints(c._hitPoints), _energyPoints(c._energyPoints),
_attackDamage(c._attackDamage), _maxHP(c._maxHP)
{
	std::cout << "[System] ClapTrap " << c._name << "'s Clone Has Been Created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[System] Claptrap " << _name << " Left the Game!" << std::endl;
}
