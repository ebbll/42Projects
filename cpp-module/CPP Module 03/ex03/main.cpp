/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:19:57 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/26 16:22:25 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	A("diamondA");
	DiamondTrap	B("diamondB");

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	A.beRepaired(10);

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("diamondA");
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	ScavTrap	C;
	C = A;
	C.guardGate();

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.beRepaired(10);

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("diamondB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("diamondA");
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	return (0);
}
