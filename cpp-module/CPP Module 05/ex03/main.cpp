/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:59:31 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 15:15:59 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	Form*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;
	Bureaucrat	pisciner;
	Bureaucrat	bocal("bocal", 1);

	std::cout << std::endl;
	pisciner.executeForm(*rrf);

	std::cout << std::endl;
	pisciner.signForm(*rrf);
	bocal.signForm(*rrf);

	std::cout << std::endl;
	pisciner.executeForm(*rrf);
	bocal.executeForm(*rrf);

	std::cout << std::endl;
	Form*	f = someRandomIntern.makeForm("blah", "no target");

	std::cout << std::endl;
	if (rrf != nullptr)
	{
		delete rrf;
	}
	if (f != nullptr)
	{
		delete f;
	}

	std::cout << std::endl;
	return (0);
}
