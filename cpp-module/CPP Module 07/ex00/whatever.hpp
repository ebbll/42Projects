/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:25:51 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/31 19:26:38 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# include <string>

/*
다음 함수 템플릿들을 구현하시오
• swap: 두 인자의 값을 치환함, 리턴값 없음
• min: 두 인자의 값을 비교하고 작은 것을 리턴함 - 만약 두 값이 같으면 두 번째 인자를 리턴함
• max: 두 인자의 값을 비교하고 큰 것을 리턴함 - 만약 두 값이 같으면 두 번째 인자를 리턴함

위 함수들은 어떤 타입이든 인자로 받을 수 있음
유일한 요구사항은 두 인자의 타입이 같아야 하고, 모든 비교 연산자를 지원해야 한다는 것임

템플릿은 헤더 파일에 정의되어야 함
*/

template <typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T	&min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T>
const T	&max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif
