/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:28 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/26 15:29:30 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	virtual void	attack(const std::string& target);
	void	highFivesGuys(void);

	FragTrap&	operator=(const FragTrap &f);
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	virtual ~FragTrap();
};

#endif
