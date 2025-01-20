/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:39:23 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 22:32:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	virtual void	attack(const std::string& target);
	void	guardGate(void);

	ScavTrap&	operator=(const ScavTrap &s);
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &s);
	virtual ~ScavTrap();
};

#endif
