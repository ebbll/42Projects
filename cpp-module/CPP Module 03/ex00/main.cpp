/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:57:45 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 16:12:12 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A("clapA");
	ClapTrap	B;

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << "\nDefault Attack" << std::endl;
	A.attack("NoName");
	B.takeDamage(A.getAttackDamage());

	std::cout << "\nRepair 10" << std::endl;
	A.beRepaired(10);

	std::cout << "\nAttack 9" << std::endl;
	B.attack("clapA");
	A.takeDamage(9);

	std::cout << std::endl;
	ClapTrap	C;
	C = A;

	std::cout << "\nAttack 20" << std::endl;
	A.attack("NoName");
	B.takeDamage(20);

	std::cout << "\nRepair 10" << std::endl;
	B.beRepaired(10);

	std::cout << "\nDefault Attack" << std::endl;
	A.attack("NoName");
	B.takeDamage(A.getAttackDamage());

	std::cout << "\nCopy Creation" << std::endl;
	ClapTrap	D(A);

	std::cout << std::endl;
	D.displayStatus();

	std::cout << "\nRecover 6 times" << std::endl;
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(100);

	std::cout << "\nExhausted" << std::endl;
	A.beRepaired(1);

	std::cout << "\nDefault Attack" << std::endl;
	A.attack("NoName");
	B.takeDamage(A.getAttackDamage());

	std::cout << "\nRecover" << std::endl;
	B.beRepaired(500);

	std::cout << "\nAttack 5" << std::endl;
	D.attack("clapA");
	A.takeDamage(5);

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
