/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:43 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 17:09:20 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
벡터 구하기
삼각형의 면적 구하기
세 삼각형 중 하나라도 0이면 false
세 삼각형 넓이의 합이 큰 삼각형과 같으면 true
*/

static const Point	vec(const Point &p1, const Point &p2)
{
	Point	temp(p1.getX().toFloat() - p2.getX().toFloat(),
				p1.getY().toFloat() - p2.getY().toFloat());

	return (temp);
}

static Fixed	area(Point const v, Point const w)
{
	Fixed	area = ((v.getX() * w.getY()) - (v.getY() * w.getX())) / 2;

	if (area < 0)
		area = area * -1;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ABC = area(vec(b, a), vec(c, a)); // ab = b - a, ac = c - a
	Fixed	PAB = area(vec(a, point), vec(b, point));
	Fixed	PBC = area(vec(b, point), vec(c, point));
	Fixed	PCA = area(vec(c, point), vec(a, point));

	// std::cout << "ABC: " << ABC << std::endl;
	// std::cout << "PAB: " << PAB << std::endl;
	// std::cout << "PBC: " << PBC << std::endl;
	// std::cout << "PCA: " << PCA << std::endl;
	// 세 삼각형 중 하나라도 0이면 point가 테두리상에 존재
	if (PAB == 0 || PBC == 0 || PCA == 0)
		return (false);
	// 세 삼각형의 면적의 합이 총면적과 같으면 삼각형 안에 존재
	if (ABC == PAB + PBC + PCA)
		return (true);
	return (false);
}
