/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:19:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 16:15:35 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << f.getName()
		<< " because the form is classified." << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t execute " << form.getName() << std::endl;
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << getName() << " executed " << form.getName() << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	return (out << b.getName() << ", bureaucrat grade" << b.getGrade());
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat:: Grade Too High Exception");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat:: Grade Too Low Exception");
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b)
{
	std::cout << "Bureaucrat: Copy assignation" << std::endl;
	*(const_cast<std::string*>(&_name)) = b._name;
	_grade = b._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(void)
: _name("Bureaucrat Default"), _grade(150)
{
	std::cout << "Bureaucrat: Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int &grade)
: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat: Constructor with name and grade" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
: _name(b._name), _grade(b._grade)
{
	std::cout << "Bureaucrat: Copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor " << _name << std::endl;
}
