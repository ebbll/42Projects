/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:39 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 17:53:05 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &f)
{
	return (out << f.toFloat());
}

int		Fixed::getRawBits(void) const
{
	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPoint) / (1 << Fixed::_fracBits));
}

int		Fixed::toInt(void) const
{
	return (_fixedPoint >> Fixed::_fracBits);
}

bool	Fixed::operator>(const Fixed& f)
{
	return (_fixedPoint > f.getRawBits());
}

bool	Fixed::operator<(const Fixed& f)
{
	return (_fixedPoint < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f)
{
	return (_fixedPoint >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f)
{
	return (_fixedPoint <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed& f)
{
	return (_fixedPoint == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f)
{
	return (_fixedPoint != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f)
{
	Fixed temp(this->toFloat() + f.toFloat());

	return (temp);
}

Fixed	Fixed::operator-(const Fixed& f)
{
	Fixed temp(this->toFloat() - f.toFloat());

	return (temp);
}

Fixed	Fixed::operator*(const Fixed& f)
{
	Fixed temp(this->toFloat() * f.toFloat());

	return (temp);
}

Fixed	Fixed::operator/(const Fixed& f)
{
	Fixed temp(this->toFloat() / f.toFloat());

	return (temp);
}

Fixed&	Fixed::operator++(void)
{
	++_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	++_fixedPoint;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	--_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	--_fixedPoint;
	return (temp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::operator=(const Fixed &f)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->_fixedPoint = f.getRawBits();
	return	(*this);
}

Fixed::Fixed(void) : _fixedPoint(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
: _fixedPoint(i << Fixed::_fracBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
: _fixedPoint(static_cast<int>(roundf(f * (1 << Fixed::_fracBits))))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;

}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}
