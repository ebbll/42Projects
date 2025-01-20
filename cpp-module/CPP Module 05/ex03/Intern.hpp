/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:48:14 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 15:17:34 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/*
Form을 작성하는 게 꽤 성가셔서 Bureaucrat에게 하루 종일 이 일을 시키는 것은 꽤나 잔인함
다행히, 우리에겐 Intern들이 있음
이 문제에서는 Intern 클래스를 만들어야 함
Intern의 인스턴스는 name도 grade도 없으며, 어떠한 개인적 특성도 없음
Bureaucrat들은 이제 자기의 일에만 신경쓸 수 있게 되었음

그런데, Intern들에게는 하나의 중요한 능력이 있음 - 바로 makeForm() 함수임
이 함수는 두 개의 string을 인자로 받음å
첫 번째 인자는 Form의 name이고, 두 번째 인자는 Form의 target임
첫 번째 인자로 이름을 초기화하고, 두 번째 인자로 target을 초기화 한 Form의 포인터를 리턴함

이 함수를 실행하면 아래와 같이 출력됨
	Intern creates <form>
만약 인자로 받은 Form의 name이 존재하지 않으면, 이 에러를 눈으로 확인할 수 있도록 오류 메시지를 출력해야 함

가독성이 떨어지고 좋지 않은 코드를 작성하는 것을 지양할 것 - 예를 들면 if/elseif/else를 겹겹이 중첩시키는 것
이런 코드는 평가 중 fail로 처리됨
이제 피시너도 아니니까 잘 짜야 함

늘 그랬듯, 정상적으로 구현되었음을 검증할 수 있는 테스트 코드를 함께 제출할 것

예) 아래의 코드는 target이 "Bender"로 설정된 RobotomyRequestForm을 생성
{
	Intern	someRandomIntern;
	Form*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
*/

class Intern
{
public:
	class NoMatchingNameException : public std::exception
	{
		public:
			const char* what(void) const throw();
	};

	Form	*makeForm(const std::string &name, const std::string &target);

	Intern&	operator=(const Intern &i);
	Intern(void);
	Intern(const Intern &i);
	~Intern();
};

#endif
