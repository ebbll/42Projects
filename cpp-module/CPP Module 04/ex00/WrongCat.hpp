/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:55:16 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:31:25 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	std::string	getType() const;
	void	makeSound() const;

	WrongCat&	operator=(const WrongCat &wc);
	WrongCat(void);
	WrongCat(const WrongCat &wc);
	virtual ~WrongCat();
};

#endif