/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:51:01 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 20:25:36 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
	std::cout << _dogIdeas->getIdea(0) << std::endl;
}

Dog&	Dog::operator=(const Dog &d)
{
	std::cout << "Dog: Copy assignation" << std::endl;
	_type = d._type;
	delete _dogIdeas;
	_dogIdeas = new Brain(*(d._dogIdeas));
	return (*this);
}

Dog::Dog(void)
: Animal()
{
	std::cout << "Dog: Default constructor" << std::endl;
	_type = "Dog";
	_dogIdeas = new Brain();
	_dogIdeas->setIdea(0, "I am a Dog with number " + std::to_string(_dogNo));
	++_dogNo;
}

Dog::Dog(const Dog &d)
: Animal()
{
	std::cout << "Dog: Copy constructor" << std::endl;
	_type = d.getType();
	_dogIdeas = new Brain(*(d._dogIdeas));
	++_dogNo;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor" << std::endl;
	--_dogNo;
	delete _dogIdeas;
}
