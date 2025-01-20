/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:19:46 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/29 15:21:44 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

/*
사무실, 복도, 서류양식, 웨이팅 큐의 인위적인 악몽을 만들어 보자
재미 없어보인다면 유감

먼저 이 거대한 관료 기계의 작은 톱니바퀴부터 만들어야 함 - 그것이 Bureaucrat임
Bureaucrat이 가져야 할 것:
• const name
• grade : 1(가장 높은 grade)부터 150(가장 낮은 grade)까지의 값을 가짐

Bureaucrat의 인스턴스를 생성할 때, invalid한 grade를 넣으면 exception을 throw 해야 함
Bureaucrat::GradeTooHighException 그리고 Bureaucrat::GradeTooLowException

attribute를 get 할 수 있는 도구를 제공해야 함: getName() and getGrade()
그리고 grade를 증가/감소 시킬 수 있는 두 멤버 함수를 구현해야 함
이 두 함수에서 grade가 range를 벗어나면 생성자에서 발생한 exception과 동일한 exception을 throw 해야 함
grade 1이 제일 높고, 150이 제일 낮으므로 grade 3에서 증가시키면 grade 2가 됨

던져진 exception은 try-catch 문에서 캐치 가능해야 함
try
{
	do some stuff with bureaucrats
}
catch (std::exception & e)
{
	handle exception
}

입출력 연산자 << 를 오버로드 해야 하며, 아래와 같이 출력됨(괄호 뺴고)
<name>, bureaucrat grade <grade>.

정상적으로 구현되었음을 검증할 수 있는 테스트 코드를 함께 제출할 것
*/

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

	Bureaucrat&	operator=(const Bureaucrat &b);
	Bureaucrat(void);
	Bureaucrat(const std::string &name, const unsigned int &grade);
	Bureaucrat(const Bureaucrat &b);
	~Bureaucrat();
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif
