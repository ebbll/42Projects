/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:26:07 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 16:40:52 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	bocal("bocal", 1);
	Bureaucrat	cadet("cadet", 100);
	Bureaucrat	pisciner("pisciner", 150);

	ShrubberyCreationForm	sform("Seoul");
	RobotomyRequestForm		rform("Humanoid X");
	PresidentialPardonForm	pform("pardon me");

	std::cout << std::endl;
	pisciner.signForm(sform);
	pisciner.signForm(rform);
	pisciner.signForm(pform);

	std::cout << std::endl;
	bocal.executeForm(sform);
	bocal.executeForm(rform);
	bocal.executeForm(pform);

	std::cout << std::endl;
	cadet.signForm(sform);
	cadet.signForm(rform);
	cadet.signForm(pform);

	std::cout << std::endl;
	pisciner.executeForm(sform);

	std::cout << std::endl;
	bocal.signForm(sform);
	bocal.signForm(rform);
	bocal.signForm(pform);

	std::cout << std::endl;
	pisciner.executeForm(sform);
	pisciner.executeForm(rform);
	pisciner.executeForm(pform);

	std::cout << std::endl;
	cadet.executeForm(sform);
	cadet.executeForm(rform);
	cadet.executeForm(pform);

	std::cout << std::endl;
	bocal.executeForm(sform);
	bocal.executeForm(rform);
	bocal.executeForm(pform);

	std::cout << std::endl;
	std::cout << sform << std::endl;
	std::cout << std::endl;
	std::cout << rform << std::endl;
	std::cout << std::endl;
	std::cout << pform << std::endl;

	std::cout << std::endl;
	return (0);
}
