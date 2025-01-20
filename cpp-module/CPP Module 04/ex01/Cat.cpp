/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:48 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 20:25:22 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
	std::cout << _catIdeas->getIdea(0) << std::endl;
}

Cat&	Cat::operator=(const Cat &c)
{
	std::cout << "Cat: Copy assignation" << std::endl;
	_type = c._type;
	delete _catIdeas;
	_catIdeas = new Brain(*(c._catIdeas));
	return (*this);
}

Cat::Cat(void)
: Animal()
{
	std::cout << "Cat: Default constructor" << std::endl;
	_type = "Cat";
	_catIdeas = new Brain();
	_catIdeas->setIdea(0, "I am a Cat with number " + std::to_string(_catNo));
	++_catNo;
}

Cat::Cat(const Cat &c)
: Animal()
{
	std::cout << "Cat: Copy constructor" << std::endl;
	_type = c.getType();
	_catIdeas = new Brain(*(c._catIdeas));
	++_catNo;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor" << std::endl;
	--_catNo;
	delete _catIdeas;
}
