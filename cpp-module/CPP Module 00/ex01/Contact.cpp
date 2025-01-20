/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:52:34 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 15:06:12 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	Contact::CheckEmpty(std::string s) const
{
	return (s.find_first_not_of(" \t\n") == std::string::npos);
}

bool	Contact::CheckFirst() const
{
	if (CheckEmpty(first_))
		return (false);
	return (true);
}

bool	Contact::CheckLast() const
{
	if (CheckEmpty(last_))
		return (false);
	return (true);
}

bool	Contact::CheckNumber() const
{
	int	length = number_.length();

	if (CheckEmpty(number_))
		return (false);
	for (int index = 0; index < length; index++)
	{
		if (!std::isdigit(number_[index]))
			return (false);
	}
	return (true);
}

void	Contact::GetNew()
{
	std::cout << "1. First name\n: ";
	std::getline(std::cin, first_);
	if (std::cin.eof())
		exit(1);
	std::cout << "2. Last name\n: ";
	std::getline(std::cin, last_);
	if (std::cin.eof())
		exit(1);
	std::cout << "3. Nickname\n: ";
	std::getline(std::cin, nickname_);
	if (std::cin.eof())
		exit(1);
	std::cout << "4. Phone number\n: ";
	std::getline(std::cin, number_);
	if (std::cin.eof())
		exit(1);
	std::cout << "5. Darkest secret\n: ";
	std::getline(std::cin, secret_);
	if (std::cin.eof())
		exit(1);
}

void	Contact::ReplaceField(Contact newcontact)
{
	first_ = newcontact.first_;
	last_ = newcontact.last_;
	nickname_ = newcontact.nickname_;
	number_ = newcontact.number_;
	secret_ = newcontact.secret_;
}

std::string	Contact::CutString(std::string str) {
	if (str.length() > 10)
	{
		str[9] = '.';
		str.erase(10);
	}
	return (str);
}

void	Contact::DisplayBriefly(int i)
{
	std::cout << std::setw(10) << i << '|'
	<< std::setw(10) << CutString(first_) << '|'
	<< std::setw(10) << CutString(last_) << '|'
	<< std::setw(10) << CutString(nickname_) << '|' << std::endl;
}

void	Contact::DisplayAll() const
{
	std::cout << "1. First name: " << first_ << std::endl;
	std::cout << "2. Last name: " << last_ << std::endl;
	std::cout << "3. Nicknaame: " << nickname_ << std::endl;
	std::cout << "4. Phone number: " << number_ << std::endl;
	std::cout << "5. Darkest Secret: " << secret_ << '\n' << std::endl;
}
