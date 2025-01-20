/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:18:38 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/29 15:59:35 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

/*
Bureaucrat 클래스를 작성하였으니, 이들에게 업무를 배정해 봅시다
서류 더미를 작성하도록 시키는 게 적절하겠죠?

Form 클래스를 만들어 봅시다 - 이 클래스는 다음과 같은 attribute를 포함합니다
• const name
• bool - sign된 상태인지 알려주며, 생성자에선 당연히 false로 지정되어야 함
• const grade - sign 할 때 필요한 등급
• const grade - execute 할 때 필요한 등급
위 attribute들은 private이며, protected가 아님

Form의 grade는 Bureaucrat에 적용된 규칙과 같음
따라서, 특별한 경우에 exception을 throw 해야 함 - Form::GradeTooHighException 과 Form::GradeTooLowException
이전에 구현한 것과 같이 모든 attribute마다 get 함수를 작성해야 하며,
입출력 연산자 << 를 오버로드 해서 Form의 모든 정보를 출력하도록 해야 함

Form 클래스에 beSigned() 멤버 함수를 구현해야 함 - Bureaucrat을 인자로 받음
이 함수는 Form의 상태를 signed로 바꾸는데, 단 인자로 받은 Bureaucrat의 grade가 Form의 grade보다 높거나 같을 때만 signed로 바꿀 수 있음
grade가 작을 수록 높은 것임을 명심해야 함(grade 1이 제일 높고, 150이 제일 낮음)
만약 Bureaucrae이 이 Form에 sign 하기에 grade가 낮으면, Form::GradeTooLowException을 throw 함

마지막으로, signForm() 멤버 함수를 Bureaucrat 클래스에 추가하시오
Bureaucrat이 Form에 sign 할 수 있는 상태이면 아래와 같이 출력됨
	<bureaucrat> signed <form>
그렇지 않으면 아래와 같이 출력됨
	<bureaucrat> couldn’t sign <form> because <reason>.
은지생각 - 아마 괄호 빼고 출력일 듯?

정상적으로 구현되었음을 검증할 수 있는 테스트 코드를 함께 제출할 것
*/

class Form
{
private:
	const std::string	_name;
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

	std::string	getName(void) const;
	bool	getIsSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExecute(void) const;

	void	beSigned(const Bureaucrat &b);

	Form&	operator=(const Form &f);
	Form(void);
	Form(const std::string &name, const unsigned int &gradeToSign, const unsigned int &gradeToExecute);
	Form(const Form &f);
	~Form();
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
