/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:48:50 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/14 20:34:58 by eunlee           ###   ########.fr       */
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
		static void		randomChump(std::string name);

		Zombie(std::string name);
		Zombie(void);
		~Zombie();
};

#endif
