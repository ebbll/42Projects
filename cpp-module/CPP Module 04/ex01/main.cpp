/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:08:23 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 21:24:47 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	Cat::_catNo = 0;
int Dog::_dogNo = 0;

int	main(void)
{
	Animal *arr[10];

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			arr[i] = new Cat();
		} else {
			arr[i] = new Dog();
		}
	}
	std::cout << "==============================" << std::endl;
	std::cout << "Cat deep copy" << std::endl;
	{
		Cat *c = new Cat();
		std::cout << "c's Ideas" << std::endl;
		c->makeSound();
		Cat *cc = new Cat(*c);
		cc->makeSound();
		delete c;
		cc->makeSound();
		delete cc;
	}
	std::cout << "==============================" << std::endl;
	std::cout << "Dog deep copy" << std::endl;
	{
		Dog *d = new Dog();
		std::cout << "d's Ideas" << std::endl;
		d->makeSound();
		Dog *dc = new Dog(*d);
		dc->makeSound();
		delete d;
		dc->makeSound();
		delete dc;
	}
	std::cout << "==============================" << std::endl;
	for (int i = 0; i < 10; i++)
		delete arr[i];
	return 0;
}
