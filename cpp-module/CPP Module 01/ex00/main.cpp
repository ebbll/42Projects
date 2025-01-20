/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:48:56 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 13:05:25 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	stackLocalTest()
{
	Zombie	local("STACK_local");
}

int		main(void)
{
	// Create Zombie on stack
	Zombie stack1("STACK_destructor");
	// Create Zombie on heap
	Zombie *heap0 = Zombie::newZombie("HEAP_00");
	// Create Zombie on stack
	Zombie::randomChump("STACK_randomChump");
	// Create Zombie on heap
	Zombie *heap1 = Zombie::newZombie("HEAP_01");
	delete heap1;
	// Create Zombie on local function
	stackLocalTest();
	delete heap0;
	return (0);
}
