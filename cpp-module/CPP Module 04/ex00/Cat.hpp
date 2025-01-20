/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:50 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:36:56 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
public:
	virtual std::string	getType() const;
	virtual void	makeSound() const;

	Cat&	operator=(const Cat &c);
	Cat(void);
	Cat(const Cat &c);
	virtual ~Cat();
};

#endif
