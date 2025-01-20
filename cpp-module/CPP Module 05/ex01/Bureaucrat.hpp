/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:19:46 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/29 14:38:11 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned int	_grade;

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

	std::string	getName(void) const;
	unsigned int	getGrade(void) const;
	void	increaseGrade(void);
	void	decreaseGrade(void);
	void	signForm(Form &f);

	Bureaucrat&	operator=(const Bureaucrat &b);
	Bureaucrat(void);
	Bureaucrat(const std::string &name, const unsigned int &grade);
	Bureaucrat(const Bureaucrat &b);
	~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif
