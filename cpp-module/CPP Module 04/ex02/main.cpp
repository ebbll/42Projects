/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:38:10 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:50:03 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	Cat::_catNo = 0;
int Dog::_dogNo = 0;

int	main(void)
{
	//Animal	a;
	//Animal *ac = new Cat();
	Cat *c = new Cat();
	Dog *d = new Dog();

	c->makeSound();
	d->makeSound();

	delete c;
	delete d;
}
