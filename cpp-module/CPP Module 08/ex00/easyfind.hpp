/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:03:25 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 16:22:35 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <exception>

/*
첫 번째 문제는 간단함
타입 T를 받는 함수 템플릿 easyfind를 작성하시오
easyfind는 두 개의 매개변수를 받는데, 첫 번째 매개변수는 T 타입으로 들어오며, 두 번째 매개변수는 int임
T가 int의 container일 때, easyfind는 int의 컨테이너인 첫 번째 매개변수 T 안에서
두 번째 매개변수인 int 값이 처음 등장하는 곳을 찾아야 함
만약 등장하는 곳을 찾을 수 없다면, exception을 throw해도 되고 에러 값을 리턴해도 됨
이러한 경우 표준 컨테이너가 어떻게 동작하는 지 테스트 해 보고 따라해도 됨
정상 동작을 검증할 수 있는 테스트 코드를 직접 구현해 제출해야 함

추가) 연관 컨테이너(associative container)는 다룰 필요 없음
associative container: (key, value)처럼 연관된 데이터를 하나의 쌍 형태로 제공
예: set, multiset, map, multimap 등

sequence container: 모든 요소들을 선형적인 순차열로 저장하는 형태
예: vector, list, deque
*/

class FindException : public std::exception
{
	public:
	const char* what(void) const throw()
	{
		return ("Array:: Cannot Find Element Exception");
	}
};

template <typename T>
typename T::iterator	easyfind(T &t, int &toFind)
{
	typename T::iterator iter = std::find(t.begin(), t.end(), toFind);
	if (iter == t.end())
		throw FindException();
	return (iter);
}

#endif
