/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:11:17 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 20:25:42 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string	Brain::getIdea(const int i) const
{
	return (_ideas[i]);
}

void	Brain::setIdea(const int i, const std::string newIdea)
{
	_ideas[i] = newIdea;
}

Brain&	Brain::operator=(const Brain &b)
{
	std::cout << "Brain: Copy assignation" << std::endl;
	for (int i = 0 ; i < 100 ; ++i)
		setIdea(i, b.getIdea(i));
	return (*this);
}

Brain::Brain(void)
{
	std::cout << "Brain: Default constructor" << std::endl;
}

Brain::Brain(const Brain &b)
{
	std::cout << "Brain: Copy constructor" << std::endl;
	for (int i = 0; i < 100; ++i)
		setIdea(i, b.getIdea(i));
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor" << std::endl;
}
