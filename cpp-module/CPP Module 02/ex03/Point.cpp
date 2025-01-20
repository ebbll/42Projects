/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:53 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/22 22:19:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream& operator<<(std::ostream& out, const Point& p) {
  return out << "( " << p.getX().toFloat() << ", " << p.getY().toFloat() << " )";
}

const Fixed&	Point::getX(void) const
{
	return (_x);
}

const Fixed&	Point::getY(void) const
{
	return (_y);
}

Point&	Point::operator=(const Point &p)
{
	const_cast<Fixed&>(_x) = p._x;
	const_cast<Fixed&>(_x) = p._y;
	return (*this);
}

Point::Point(void)
: _x(0), _y(0)
{

}

Point::Point(const Point &p)
: _x(p._x), _y(p._y)
{

}

Point::Point(const float x, const float y)
: _x(x), _y(y)
{

}

Point::~Point()
{

}
