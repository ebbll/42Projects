/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:32:26 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 15:40:29 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		void			announce(void) const;
		static Zombie	*newZombie(std::string name);
		static Zombie*	zombieHorde(int N, std::string name);

		void			setName(std::string name);
		Zombie(std::string name);
		Zombie(void);
		~Zombie();
};

#endif
