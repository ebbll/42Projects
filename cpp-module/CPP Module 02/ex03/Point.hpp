/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:50 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 17:01:34 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;

		Point&	operator=(const Point &p);
		Point(void);
		Point(const Point &p);
		Point(const float x, const float y);
		~Point();
};

std::ostream&	operator<<(std::ostream& out, const Point& p);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
