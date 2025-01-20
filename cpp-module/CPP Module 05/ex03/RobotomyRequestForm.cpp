/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:15:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 15:08:35 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);
	std::cout << "bzzzzzz..." << std::endl;
	srand(time(NULL));
	int	randomNum = rand() % 10;
	if (randomNum > 5)
	{
		std::cout << "the robotomy failed" << std::endl;
	} 
	else
	{
		std::cout << getTarget()
			<< " has been robotomized successfully" << std::endl;
	}
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &r)
{
	return *(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(r))));
}

RobotomyRequestForm::RobotomyRequestForm(void)
: Form()
{
	std::cout << "RobotomyRequestForm: Default constructor" << std::endl;
	setName("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: Form("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "RobotomyRequestForm: Constructor with target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r)
: Form(r)
{
	std::cout << "RobotomyRequestForm: Copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor to target " << getTarget() << std::endl;
}
