/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:43:39 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 15:26:54 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

/*
이제 좀 더 중요한 것을 할 때가 왔음
이상한 것을 만들어 보자

std::stack 은 아주 우수한 컨테이너임
그런데 몹시 유감스럽게도 이것은 STL 컨테이너 중 유일하게 iterate를 적용할 수 없음

그렇다면 참을 수 없지
특히 우리는 원래 스택을 조져서 빠진 기능을 만들 수 있는 능력이 있음

이 불공평한 점을 고치기 위해, iterable한 std::stack 컨테이너를 만들어 보자

MutantStack 클래스를 만드시오
이 클래스는 std::stack의 측면에서 구현됨
이 클래스는 std::stack의 멤버 함수를 모두 제공하며, 여기에 추가로 iterator라는 특성을 적용함

물론 모든 구현을 검증할 수 있는 테스트 코드를 함께 제출해야 함

위와 같은 테스트 코드를 실행해 보시오
우선 첫 번째는 직접 구현한 MutantStack으로 실행해 보고, 그 다음엔 MutantStack 대신 std::list 같은 것을 넣어서 실행해 보시오
두 개의 결과는 같아야 함
물론 다른 컨테이너를 넣는 경우엔 그 컨테이너에 해당하는 함수로 바꿔줘야 함
예) push() 대신 push_back()으로
*/

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename
		std::stack<T>::container_type::iterator
		iterator;
	typedef typename
		std::stack<T>::container_type::const_iterator
		const_iterator;
	typedef typename
		std::stack<T>::container_type::reverse_iterator
		reverse_iterator;
	typedef typename
		std::stack<T>::container_type::const_reverse_iterator
		const_reverse_iterator;

	iterator begin(void)
	{
		return this->c.begin();
	}

	iterator end(void)
	{
		return this->c.end();
	}

	const_iterator cbegin(void) const
	{
		return this->c.cbegin();
	}

	const_iterator cend(void) const
	{
		return this->c.cend();
	}

	reverse_iterator rbegin(void)
	{
		return this->c.rbegin();
	}

	reverse_iterator rend(void)
	{
		return this->c.rend();
	}

	const_reverse_iterator crbegin(void) const
	{
		return this->c.crbegin();
	}

	const_reverse_iterator crend(void) const
	{
		return this->c.crend();
	}

	MutantStack& operator=(const MutantStack& m)
	{
		if (this != &m)
		{
			std::stack<T>::operator=(m);
		}
		return (*this);
	}

	MutantStack(void) {}
	MutantStack(const MutantStack& m) { *this = m; }
	~MutantStack() {}
};

#endif

/*
LIFO stack - Last in first out
template <typename T, typename Container = deque<T> > class stack;
템플릿의 첫 번째 파라미터인 T는 element의 타입을 의미
템플릿의 두 번째 파라미터인 Container는 T 타입의 element들을 저장하는 기저 컨테이너
이 기저 컨테이너는 empty, size, back, push_back, pop_back을 지원함
기저 컨테이너는 deque으로 구현되어 있는 듯?

class stack
{
public:
	1. 멤버 타입
	value_type; : 템플릿의 첫 번째 파라미터인 T, element의 타입을 의미
	container_type; : 템플릿의 두 번째 파라미터인 Container, 즉 기저 컨테이너이며 T 타입을 저장함
	size_type; : size_t와 같음, unsigned 크기값

	2. 멤버 함수
	생성자
	empty
	size
	top
	push
	pop
}
*/
