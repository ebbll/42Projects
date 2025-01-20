/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:08 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 16:49:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int	_fixedPoint;
		static const int	_fracBits = 8;

	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed&	operator=(const Fixed &f);
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed();
};

#endif
