/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:08:37 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/23 16:57:04 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

/*
1. 연산자 오버로딩 구현하기
• 비교연산자: > < >= <= == !=
• 산술연산자: + - * /
• 전/후위 증감연산자 4가지 ++a, a++, --a, a--
1 + ε > 1로 표현할 수 있는 정도의 ε만큼을 증감

public static 멤버 함수 오버로드
• min
	인자: 두 개의 고정소수점의 레퍼런스
	반환: 가장 작은 값의 레퍼런스
• min의 오버로드
	인자: 두 개의 const 고정소수점의 레퍼런스
	반환: 가장 작은 값의 레퍼런스
• max
	인자: 두 개의 고정소수점의 레퍼런스
	반환: 가장 큰 값의 레퍼런스
• max의 오버로드
	인자: 두 개의 const 고정소수점의 레퍼런스
	반환: 가장 큰 값의 레퍼런스
*/

class Fixed
{
	private:
		int	_fixedPoint;
		static const int	_fracBits = 8;

	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);

		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

		Fixed&	operator=(const Fixed &f);
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &f);
		~Fixed();
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif
