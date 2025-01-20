/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:13:21 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/13 21:21:00 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::count_ = 0;
int PhoneBook::oldest_ = 0;

int main(void)
{
	std::string	cmd;
	PhoneBook	book;

	while (!std::cin.eof())
	{
		std::cout
		<< " ---------------------\n" 
		<< "| Please select mode  |\n"
		<<"| ADD | SEARCH | EXIT |\n"
		<< " ---------------------\n"
		<< ">> ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
		{
			break ;
		}
		else if (cmd == "ADD")
		{
			book.AddPhoneBook();
		}
		else if (cmd == "SEARCH")
		{
			book.SearchPhoneBook();
		}
		else
			std::cout << "Wrong command! Try again :(\n" << std::endl;
	}
	return (0);
}
