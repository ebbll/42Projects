/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:51:03 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 21:05:05 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	static int	_dogNo;
	Brain	*_dogIdeas;
public:
	void	makeSound() const;

	Dog&	operator=(const Dog &d);
	Dog(void);
	Dog(const Dog &d);
	virtual ~Dog();
};

#endif
