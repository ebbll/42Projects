/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:48:16 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 16:36:51 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*	Intern::NoMatchingNameException::what(void) const throw()
{
	return ("Intern:: No Matching Name Exception");
}

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string	format[3] = {"shrubbery creation",
							"robotomy request",
							"presidential pardon"};
	try
	{
		for (int i = 0; i < 3; ++i)
		{
			if (format[i] == name)
			{
				std::cout << "Intern makes " << name << " form to target " 
				<< target << std::endl;
				switch (i)
				{
				case 0:
					return (new ShrubberyCreationForm(target));
					break;
				case 1:
					return (new RobotomyRequestForm(target));
					break;
				case 2:
					return (new PresidentialPardonForm(target));
					break;
				}
			}
		}
		throw Intern::NoMatchingNameException();
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern couldn't create form" << std::endl;
		std::cerr << e.what() << '\n';
		return (nullptr);
	}
}

Intern&	Intern::operator=(const Intern &i)
{
	std::cout << "Intern: Copy assignation" << std::endl;
	static_cast<void>(i);
	return (*this);
}

Intern::Intern(void)
{
	std::cout << "Intern: Default constructor" << std::endl;
}

Intern::Intern(const Intern &i)
{
	std::cout << "Intern: Copy constructor" << std::endl;
	static_cast<void>(i);
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor" << std::endl;
}
