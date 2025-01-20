/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:51:03 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:36:46 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
public:
	virtual std::string	getType() const;
	virtual void	makeSound() const;

	Dog&	operator=(const Dog &d);
	Dog(void);
	Dog(const Dog &d);
	virtual ~Dog();
};

#endif
