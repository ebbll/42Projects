/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:15 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 22:32:17 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <iomanip>
# include <string>

# define	DFLNAME		"NoName"

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	const unsigned int	_maxHP;

public:
	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getAttackDamage(void);
	void	displayStatus(void);

	ClapTrap&	operator=(const ClapTrap &c);
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &c);
	virtual ~ClapTrap();
};

#endif
