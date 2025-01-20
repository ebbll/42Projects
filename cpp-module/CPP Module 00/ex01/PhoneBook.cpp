/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:10:23 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 15:04:43 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "INITIATING PHONEBOOK..." << std::endl;
	std::cout << "Welcome, eunlee!\n" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\nCLOSING PHONEBOOK..." << std::endl;
	std::cout << "Goodbye, eunlee!" << std::endl;
}

void	PhoneBook::AddPhoneBook()
{
	std::cout << "\nCOLLECTING NEW DATA...\n" << std::endl;
	newcontact.GetNew();
	if (!newcontact.CheckFirst() || !newcontact.CheckLast())
	{
		std::cout << "Wrong name! Contact creation failed. Try again :(\n" << std::endl;
		return ;
	}
	if (!newcontact.CheckNumber())
	{
		std::cout << "Wrong number! Contact creation failed. Try again :(\n" << std::endl;
		return ;
	}
	std::cout << "New contact created successfully! :)\n" << std::endl;

	if (count_ < 8)
	{
		book[count_].ReplaceField(newcontact);
		count_++;
	}
	else
	{
		std::cout << "Phonebook is Full! Removing oldest data...\n" << std::endl;
		book[oldest_].ReplaceField(newcontact);
		oldest_ = (oldest_ + 1) % 8;
	}
}

void	PhoneBook::SearchPhoneBook()
{
	std::string	answer;
	int			index;

	std::cout << "\nSEARCHING MODE ACTIVATING...\n" << std::endl; 
	if (count_ == 0)
	{
		std::cout << "You don't have any contacts in your phonebook yet! :)\n" << std::endl;
	}
	else
	{
		std::cout << std::setw(10) << "index" << '|'
		<< std::setw(10) << "first name" << '|'
		<< std::setw(10) << "last name" << '|'
		<< std::setw(10) << "nickname" << '|' << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < count_; i++)
		{
			book[(oldest_ + i) % 8].DisplayBriefly(i);
		}
		std::cout << "\nDo you want more information? Enter the index number\n>> ";
		getline(std::cin, answer);
		if (std::cin.eof())
			return ;
		if (answer.length() == 1 && std::isdigit(answer[0]))
		{
			index = std::stoi(answer);
			if (index >= 0 && index <= count_ - 1)
			{
				std::cout << "\n[Info of index " << index << "]" << std::endl;
				book[(oldest_ + std::stoi(answer)) % 8].DisplayAll();
				return ;
			}
		}
		std::cout << "Wrong input!\n" << std::endl;
	}
}
