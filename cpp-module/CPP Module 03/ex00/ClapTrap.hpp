/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:57:42 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 16:16:48 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <iomanip>
# include <string>

# define	DFLNAME		"NoName"

/*
ClapTrap은 다음과 같은 private attribute를 가지며, 정해진 값(괄호 안에 명시)으로 초기화됨
	• name (생성자를 통해 전달된 인자)
	• hitPoints (10): ClapTrap의 체력값
	• energyPoints (10)
	• attackDamage (0)

다음과 같은 멤버 함수를 구현하면 ClapTrap이 좀 더 실감나게 살아날 것임
	• void attack(const std::string& target);
	• void takeDamage(unsigned int amount);
	• void beRepaired(unsigned int amount);

ClapTrap이 attack()하면, target의 hitPoints를 attackDamage만큼 감소시킴
ClapTrap이 스스로를 repair()하면, amount 만큼의 hitPoints를 회복함
attack()과 repair()를 수행하는 데 1 energyPoint가 소모됨
ClapTrap의 hitPoints나 energyPoints가 0이 되면 더 이상 행동을 취할 수 없음

모든 멤버 함수에 대해 상세 메시지를 출력해야 함
예) attack()은 다음과 같은 메시지를 출력함 (괄호 빼고)
: ClapTrap <name> attacks <target>, causing <damage> points of damage!

생성자와 소멸자도 모두 메시지를 출력하도록 구현해야 함
따라서 평가자가 호출된 함수의 메시지를 확인하는 것이 가능해짐

구현한 클래스가 정상적으로 동작했는지 검증할 수 있는 적절한 테스트 코드도 함께 제출해야 함
*/

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	const unsigned int	_maxHP;

public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getAttackDamage(void) const;
	void	displayStatus(void) const;

	ClapTrap&	operator=(const ClapTrap &c);
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &c);
	~ClapTrap();
};

#endif
