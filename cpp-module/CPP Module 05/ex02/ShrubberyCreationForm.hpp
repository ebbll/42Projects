/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:15:18 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/29 20:43:37 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

/*
Form의 토대를 만들었으니, 이제 실제로 무언가 할 수 있는 것을 만들어야 함
base 클래스가 될 Form은 이제 abstract(추상) 클래스가 되어야 함
base 클래스인 Form의 attribute들은 private으로 유지되어야 함

다음의 concrete(구상) 클래스를 추가로 구현해야 함 - 구상 클래스는 추상 클래스를 상속받아 구체화(오버라이드) 한 것
• ShrubberyCreationForm - shrubbery는 관목숲 이라는 뜻
	grade 설정: sign 145, exec 137
	현재 작업중인 디렉토리에 <target>_shrubbery 파일을 만들고, 내용은 ASCII trees를 씀
• RobotomyRequestForm
	grade 설정: sign 72, exec 45
	시끄러운 드릴 소음을 만듦
	그리고 나서, "<target> has been robotomized successfully 50% of the time" 이라고 알려줌
	그렇지 않은 경우, "the robotomy failed" 라고 알려줌
• PresidentialPardonForm
	grade 설정: sign 25, exec 5
	"<target> has been pardoned by Zaphod Beeblebrox" 라고 알려줌
위 클래스들은 생성자에서 하나의 인자만을 받음 - Form의 target
예) "home"에 shrubbery를 심고 싶으면 "home"을 인자로 줌

이제 execute(Bureaucrat const & executor) const 멤버 함수를 base 클래스인 Form에 추가하시오
그리고 Form의 행동을 수행할 수 있는 함수를 concrete(구상) 클래스에 추가하시오
우선 Form이 signed 상태인지 확인한 뒤, 이를 execute하려는 Bureaucrat의 grade가 적절한지 확인해야 함(높거나 같아야 함)
예외의 경우, exception을 throw 해야 함

모든 구상 클래스에서 요구 사항을 확인할지, 아니면 베이스 클래스에서 확인한 뒤 다른 함수를 호출해서 Form을 execute 할 지
둘 중 하나를 고르는 것은 자유임
하지만 두 방법 중 하나가 더 예쁘고 적절하긴 할 테니, 무엇이 적당할 지 직접 생각해 보고 결정해야 함

마지막으로, executeForm(Form const & form) 멤버 함수를 Bureaucrat 클래스에 추가하시오
이 함수는 Form을 execute 하려는 시도를 함
만약 성공적으로 execute 되었다면 아래와 같이 출력
	<bureaucrat> executed <form>
그렇지 않으면, 오류를 눈으로 확인할 수 있도록 에러 메시지를 출력

정상적으로 구현되었음을 검증할 수 있는 테스트 코드를 함께 제출할 것
*/

class ShrubberyCreationForm : public Form
{
private:
	ShrubberyCreationForm(void);

public:
	void	execute(Bureaucrat const & executor) const;

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &s);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &s);
	~ShrubberyCreationForm();
};

#endif
