/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:42:07 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 16:07:54 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

/*
ClapTrap을 상속하는 또 하나의 클래스 FragTrap 만들기
하지만, FragTrap의 생성자, 소멸자는 다른 메시지를 출력해야 함
테스트 과정에서 온전한 생성자/소멸자 체인을 확인할 수 있어야 함
ScavTrap이 생성될 때, 프로그램은 우선 ClapTrap을 먼저 만들어야 함
소멸자는 반대의 순서임

같은 attribute를 가지지만, 값은 다름
• Name(생성자의 인자로 전달된 값으로)
• Hit points (100): ClapTrap의 체력
• Energy points (100)
• Attack damage (30)

FragTrap은 그만의 고유한 능력을 가짐
	void highFivesGuys(void);
이 멤버 함수는 표준출력으로 positive high five 요청을 출력해야 함

테스트에 적합한 main.cpp를 작성해야 함
*/

class FragTrap : public ClapTrap
{
public:
	virtual void	attack(const std::string& target);
	void	highFivesGuys(void);

	FragTrap&	operator=(const FragTrap &f);
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	virtual ~FragTrap();
};

#endif
