/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 20:57:20 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
protected:
	std::string	_type;

public:
	std::string	getType(void) const;
	virtual void	makeSound() const;

	Animal&	operator=(const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();
};

#endif
