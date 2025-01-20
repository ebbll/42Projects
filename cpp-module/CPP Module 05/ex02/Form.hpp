/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:18:38 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/29 17:22:00 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <fstream>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	const std::string	_target;
	bool	_isSigned;
	const unsigned int	_gradeToSign;
	const unsigned int	_gradeToExecute;

public:
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class DoesNotSignedException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	class FileErrorException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	std::string	getName(void) const;
	std::string	getTarget(void) const;
	bool	getIsSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExecute(void) const;

	void	setName(const std::string &name);
	void	setTarget(const std::string &target);

	void	beSigned(const Bureaucrat &b);
	void	checkExecutable(Bureaucrat const & executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

	Form&	operator=(const Form &f);
	Form(void);
	Form(const std::string &name, const std::string &target, const unsigned int &gradeToSign, const unsigned int &gradeToExecute);
	Form(const Form &f);
	virtual ~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
