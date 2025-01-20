/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:18:40 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 16:18:15 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::ostream&	operator<<(std::ostream& out, const Form& f)
{
	if (f.getIsSigned() == true)
	{
		return (out << "Form " << f.getName() << " Status\n"
				<< "Signed\nGrade to sign: " << f.getGradeToSign()
				<< "\nGrade to execute: " << f.getGradeToExecute());
	}
	else
	{
		return (out << "Form " << f.getName() << " Status\n"
				<< "Not signed\nGrade to sign: " << f.getGradeToSign()
				<< "\nGrade to execute: " << f.getGradeToExecute());
	}
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Form:: Grade Too High Exception");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Form:: Grade Too Low Exception");
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (_gradeToSign < b.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		_isSigned = true;
	}
}

Form&	Form::operator=(const Form &f)
{
	std::cout << "Form: Copy assignation" << std::endl;
	*(const_cast<std::string*>(&_name)) = f._name;
	_isSigned = f._isSigned;
	*(const_cast<unsigned int*>(&_gradeToSign)) = f._gradeToSign;
	*(const_cast<unsigned int*>(&_gradeToExecute)) = f._gradeToExecute;
	return (*this);
}

Form::Form(void)
: _name("FreeStyle"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form: Default constructor" << std::endl;
}

Form::Form(const std::string &name, const unsigned int &gradeToSign, const unsigned int &gradeToExecute)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form: Constructor with name and grade" << std::endl;
}

Form::Form(const Form &f)
: _name(f.getName()), _isSigned(f.getIsSigned()), _gradeToSign(f.getGradeToSign()), _gradeToExecute(f.getGradeToExecute())
{
	std::cout << "Form: Copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form: Destructor " << _name << std::endl;
}
