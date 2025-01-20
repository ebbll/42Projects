/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:50 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 15:00:59 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	static int	_catNo;
	Brain	*_catIdeas;
public:
	virtual void	makeSound() const;

	Cat&	operator=(const Cat &c);
	Cat(void);
	Cat(const Cat &c);
	virtual ~Cat();
};

#endif
