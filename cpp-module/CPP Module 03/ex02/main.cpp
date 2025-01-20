/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:42:10 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/25 22:17:16 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	A("scavA");
	FragTrap	B("fragZ");
	A.guardGate();
	B.highFivesGuys();

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	A.beRepaired(10);

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("scavA");
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	ScavTrap	C;
	C = A;
	C.guardGate();

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.beRepaired(10);

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	A.attack("fragZ");
	B.takeDamage(A.getAttackDamage());

	std::cout << std::endl;
	B.attack("scavA");
	A.takeDamage(B.getAttackDamage());

	std::cout << std::endl;
	A.displayStatus();

	std::cout << std::endl;
	B.displayStatus();

	std::cout << std::endl;
	return (0);
}
