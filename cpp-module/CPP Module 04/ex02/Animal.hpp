/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 21:15:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

/*
순수 가상 함수 - 추상 클래스
Creating Animal objects doesn’t make sense after all.
It’s true, they make no sound!

To avoid any possible mistakes, the default Animal class should not be instantiable.
Fix the Animal class so nobody can instantiate it.
Everything should work as before.

If you want to, you can update the class name by adding a A prefix to Animal.
*/

class Animal
{
protected:
	std::string	_type;

public:
	std::string	getType(void) const;
	virtual void	makeSound() const = 0;

	Animal&	operator=(const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();
};

#endif
