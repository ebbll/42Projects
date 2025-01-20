/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:43:21 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/26 16:32:16 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/*
DiamondTrap이라는 FragTrap과 ScavTrap의 혼종을 만드시오

DiamondTrap 클래스는 private attribute로 name을 가짐
기반 클래스 ClapTrap과 동일한 변수명으로 설정
ClapTrap의 이름 변수명이 name이면 DiamondTrap도 name으로, _name이면 _name으로

Diamond의 Attribute 및 멤버는 FragTrap과 ScavTrap 둘 중 하나에서 택해와야 함
• name(생성자를 통해 전달된 것)
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
• hitPoints (FragTrap)
• energyPoints (ScavTrap)
• attackDamage (FragTrap)
• attack() (Scavtrap)

DiamondTrap은 자신만의 고유한 특성을 가짐:
	void whoAmI();
이 멤버 함수는 자신의 두 이름과 ClapTrap으로서의 이름 모두를 출력함
DiamondTrap의 서브객체인 ClapTrap은 당연하게도 단 한 번만 생성됨 - 이 점을 주의해야 함
*/

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
	void	whoAmI(void) const;

	//using	FragTrap::_hitPoints;
	using	ScavTrap::_energyPoints;
	//using	FragTrap::_attackDamage;
	using	ScavTrap::attack;

	DiamondTrap&	operator=(const DiamondTrap &d);
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &d);
	virtual ~DiamondTrap();
};

#endif
