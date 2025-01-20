/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:28:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/17 22:05:29 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]"
	<< "I love to get extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I just love it!\n"
	<< std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]"
	<< "I cannot believe adding extra bacon cost more money. "
	<< "You don’t put enough! If you did I would not have to ask for it!\n"
	<< std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]"
	<< "I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming here for years and you just started working here "
	<< "last month.\n"
	<< std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]"
	<< "This is unacceptable, I want to speak to the manager now.\n"
	<< std::endl;
}

void	Karen::basic(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]"
	<< std::endl;
}

void	Karen::complain(std::string level)
{
	int	ret = -1;
	void (Karen::*f[5])(void) =	{&Karen::basic,
								&Karen::debug,
								&Karen::info,
								&Karen::warning,
								&Karen::error};
	std::string	message[4] =	{"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == message[i])
			ret = i;
	switch (ret)
	{
	case -1:
		(this->*(f[0]))();
		break;
	case 0:
		(this->*(f[1]))();
	case 1:
		(this->*(f[2]))();
	case 2:
		(this->*(f[3]))();
	case 3:
		(this->*(f[4]))();
		break;
	}
}

Karen::Karen(void)
{

}

Karen::~Karen()
{

}
