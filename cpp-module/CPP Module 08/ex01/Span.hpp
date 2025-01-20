/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:20:06 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 17:39:01 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <numeric>

/*
최대 N개의 int를 저장할 수 있는 Span 클래스를 만드시오
N은 unsigned int 변수이며, 생성자가 받는 유일한 인자임

이 클래스는 addNumber()라는 멤버 함수를 가지는데, Span에 숫자 하나를 추가하는 함수임
Span을 채울 때 이 함수를 사용하면 됨
만약 이미 N개의 element가 있는데 addNumber()를 하려고 하면 exception을 throw 해야 함

그 다음, 다음 멤버 함수 두 개를 추가하시오: shortestSpan() longestSpan()
두 함수는 Span 안에 저장된 숫자들 중 각각 제일 짧은 span 또는 제일 긴 span을 찾아 리턴해 줌
span 대신 distance를 리턴해도 됨
만약 저장된 숫자가 없거나 1개만 있으면 span을 구할 수 없으므로, 이런 경우에는 exception을 throw 해야 함

당연하게도 직접 테스트 코드를 작성해야 하며, 서브젝트에 주어진 메인문보다 더 철저해야 함
최소한 10000개의 숫자를 활용해 Span을 테스트 해야 하며, 많은 숫자로 테스트 할수록 더 좋음

아래 주어진 메인문을 실행한 경우, 예시와 같이 결과가 나와야 함(서브젝트 참고)

마지막으로 가장 중요한 점은, range iterator를 사용해 Span을 채워 보는 것이 좋음
수천번 addNumber()를 호출하는 것은 매우 짜증나니까~
Span에 한 번에 여러 개의 숫자를 추가할 수 있는 멤버 함수를 구현하시오

만약 모르는 점이 생기면 컨테이너를 공부하시오
몇몇 멤버 함수는 컨테이너에 일련의 element를 쭉 넣기 위해 range iterator를 받기도 함
*/

class Span
{
private:
	const unsigned int	_size;
	std::vector<int>	_data;

	Span(void);

public:
	class FullException : public std::exception
	{
		const char* what(void) const throw()
		{
			return ("Full of Elements Exception");
		}
	};

	class LackException : public std::exception
	{
		const char* what(void) const throw()
		{
			return ("Lack of Elements Exception");
		}
	};

	class ExceedSizeException : public std::exception
	{
		const char* what(void) const throw()
		{
			return ("Exceed Span Size Exception");
		}
	};

	unsigned int	getElementCount(void) const;
	unsigned int	getSize(void) const;

	void	addNumber(const int &value);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	void	generateNumbers(const unsigned int &count);
	void	displaySpan(void);

	Span&	operator=(const Span &s);
	Span(unsigned int N);
	Span(const Span &s);
	~Span();
};

#endif
