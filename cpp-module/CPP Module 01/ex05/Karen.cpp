/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:00:08 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/17 22:00:59 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I just love it!"
	<< std::endl;
}

void	Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
	<< "You don’t put enough! If you did I would not have to ask for it!"
	<< std::endl;
}

void	Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming here for years and you just started working here "
	<< "last month."
	<< std::endl;
}

void	Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}

void	Karen::complain(std::string level)
{
	void (Karen::*f[4])(void) =	{&Karen::debug,
								&Karen::info,
								&Karen::warning,
								&Karen::error};
	std::string message[4] =	{"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == message[i])
			(this->*(f[i]))();
}

Karen::Karen(void)
{

}

Karen::~Karen()
{

}
