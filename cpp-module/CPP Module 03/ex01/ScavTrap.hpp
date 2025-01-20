/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:38:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 16:23:17 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

/*
ClapTrap의 부족한 부분을 보완하여 파생 로봇을 만들어야 함
ScavTrap은 ClapTrap의 생성자와 소멸자를 상속함
하지만, ScavTrap의 생성자, 소멸자, attack()은 다른 메시지를 출력해야 함
ClapTraps은 각자의 고유 특성을 알고 있음

테스트 과정에서 온전한 생성자/소멸자 체인을 확인할 수 있어야 함
ScavTrap이 생성될 때, 프로그램은 우선 ClapTrap을 먼저 만들어야 함
소멸자는 반대의 순서임 - 이유를 생각해보자

ScavTrap은 ClapTrap의 attribute를 가짐(그 결과로 ClapTrap을 업데이트하게 됨)
값 초기화는 다음과 같이 함
	• name(생성자의 인자로 전달된 값으로)
	• hitPoints (100): ClapTrap의 체력
	• energyPoints (50)
	• attackDamage (20)

ScavTrap은 그만의 고유한 능력을 가짐
	void guardGate();
이 멤버 함수는 ScavTrap이 Gate keeper mode가 되었다는 메시지를 출력
예) "ScavTrap is now in Gate keeper mode"

테스트에 적합한 main.cpp를 작성해야 함
*/

class ScavTrap : public ClapTrap
{
public:
	virtual void	attack(const std::string& target);
	void	guardGate(void);

	ScavTrap&	operator=(const ScavTrap &s);
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &s);
	virtual ~ScavTrap();
};

#endif
