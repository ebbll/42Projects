/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:55:18 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:38:14 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string	_type;

public:
	std::string	getType(void) const;
	void	makeSound() const;

	WrongAnimal&	operator=(const WrongAnimal &wa);
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &wa);
	virtual ~WrongAnimal();
};

#endif