/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:02:53 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 16:25:58 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	A("scavA");
	ScavTrap	B("scavB");

	A.guardGate();
	B.guardGate();

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	A.beRepaired(10);

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("scavA");
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	std::cout << "\nAssignation" << std::endl;
	ScavTrap	C;
	C = A;
	C.guardGate();

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.beRepaired(10);

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << "\nCopy Creation" << std::endl;
	ScavTrap	D(A);
	D.guardGate();

	std::cout << std::endl;
	D.displayStatus();

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("scavB");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("scavA");
	//A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	ClapTrap	X("clapX");

	std::cout << std::endl;
	X.attack("scavA");
	A.takeDamage(X.getAttackDamage());

	std::cout << std::endl;
	A.attack("clapX");
	X.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	C.displayStatus();

	std::cout << std::endl;
	D.displayStatus();

	std::cout << std::endl;
	return (0);
}
