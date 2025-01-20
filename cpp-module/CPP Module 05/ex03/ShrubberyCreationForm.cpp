/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:15:16 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 14:23:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutable(executor);
	std::ofstream	out(getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (!out.good())
		throw Form::FileErrorException();
	std::string	shrubbery
	=	" ^  ^  ^   ^   ^  ^   ^  ^  ^   ^  ^\n"
		"/|\\/|\\/|\\ /|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		"/|\\/|\\/|\\ /|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		"/|\\/|\\/|\\ /|\\ /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\";
	out << shrubbery;
	out.close();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	return *(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(s))));
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
: Form()
{
	std::cout << "ShrubberyCreationForm: Default constructor" << std::endl;
	setName("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: Form("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm: Constructor with target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
: Form(s)
{
	std::cout << "ShrubberyCreationForm: Copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor to target " << getTarget() << std::endl;
}
