/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:48:38 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 14:18:18 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cerrno>
# include <cctype>
# include <cmath>

/*
가장 일반적인 형태의 C++ 리터럴 표현(string 타입)을 인자로 받는 프로그램을 작성하시오
리터럴: 어떠한 '값'을 나타내는 데 사용되는 데이터 (예) 1, 2.5, 'c'
이 리터럴은 무조건 다음의 스칼라 타입 중 하나여야만 함 - char, int, float, double
	(은지생각) 스칼라 타입: 자료형과 비슷한 개념인 듯?
char 파라미터를 제외하고 나머지는 모두 10진수 표기법이 사용됨

1. char 리터럴 예시: ’c’, ’a’..
인풋으로 들어오는 char에 출력 불가 문자는 포함되지 않으므로, 구현이 조금은 간단해 질 것임
만약 char로 conversion한 결과가 출력 불가라면, 이를 알리는 메시지를 출력해야 함

2. int 리터럴 예시: 0, -42, 42...

3. float 리터럴 예시: 0.0f, -4.2f, 4.2f...
-inff, +inff, nanf와 같은 유사 리터럴 값들도 다루어야 함

4. double 리터럴 예시: 0.0, -4.2, 4.2...
-inf, +inf, nan과 같은 유사 리터럴 값들도 다루어야 함

먼저 인자로 들어온 리터럴의 타입을 알아내기
그리고 이 string 타입을 바꾸어야 할 타입으로 바꿔주기
그 다음 명시적으로 타입을 바꾸어 주기 - 나머지 세 개의 타입으로
마지막으로, 아래와 같이 결과를 출력해 주기

만약 conversion 과정에서 이론적으로 맞지 않는 일이나 overflow가 발생하면
conversion이 불가능 하다는 것을 알리기 위해 유저에게 메시지를 출력해 주어야 함
numeric limit 및 특별한 값들을 처리하기 위해 어떤 header를 include하든 상관 없음
*/

enum	State
{
	FINE,
	RANGE,
	NODATA
};

class Convert
{
private:
	double	_data;
	std::string	_str;
	int	_state;

	Convert(void);

public:
	void printChar(void) const;
	void printInt(void) const;
	void printFloat(void) const;
	void printDouble(void) const;

	Convert&	operator=(const Convert& c);
	Convert(const std::string& str);
	Convert(const Convert& c);
	~Convert();
};

#endif
