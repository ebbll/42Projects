/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:15:23 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 14:21:58 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
	<< std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
	return *(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(p))));
}

PresidentialPardonForm::PresidentialPardonForm(void)
: Form()
{
	std::cout << "PresidentialPardonForm: Default constructor" << std::endl;
	setName("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: Form("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "PresidentialPardonForm: Constructor with target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
: Form(p)
{
	std::cout << "PresidentialPardonForm: Copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor to target " << getTarget() << std::endl;
}
