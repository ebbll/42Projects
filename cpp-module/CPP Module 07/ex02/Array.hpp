/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:36:23 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 18:41:46 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

/*
클래스 템플릿 Array를 만드시오
Array에는 T 타입의 element가 들어있고, 다음의 기능 및 함수를 실행할 수 있음

• 기본 생성자: 빈 array를 생성함
• unsigned int n을 받는 생성자: n개의 element를 갖는 array를 만들고, 모든 element의 값은 디폴트와 같이 초기화 됨
	팁: int * a = new int(); 를 실행해 보고 *a를 출력해 보기
• 복사 생성자 및 대입 연산자 오버로드: 두 경우 모두 복사해 온 뒤 original array나 복사본 array의 값을 변경하는 것은 서로에게 영향을 끼치지 않음
	깊은 복사 하라는 뜻인 듯?
• 반드시! 메모리 할당하는 경우 new[] 키워드를 사용해야 함!
	preventive allocation(추가로 메모리를 할당하는 것)은 금지되어 있음
	프로그램에서 할당되지 않은 메모리에 접근하는 일은 없어야 함
• element들은 [ ]와 같은 접근 연산자로 접근 가능해야 함
• [ ] 연산자로 접근하는 경우에 만약 index의 범위를 벗어나게 되면 std::exception 을 throw 해야 함
• 멤버 함수 size()를 구현하고, array의 element 개수를 리턴하게 해야 함
	이 멤버 함수는 인자를 받지 않으며, 해당 인스턴스의 어떤 값도 변형하지 않아야 함

늘 그랬던 것처럼 테스트 코드를 main.cpp 로 작성하여 제출하시오
서브젝트랑 같이 main.cpp 다운받을 수 있는데 확인 한 번 해 보기
*/

template <typename T>
class Array
{
private:
	unsigned int	_size;
	T	*_data;

public:
	class OutOfRangeException : public std::exception
	{
		public:
		const char* what(void) const throw()
		{
			return ("Array:: Out Of Range Exception");
		}
	};

	unsigned int	size(void) const
	{
		return (_size);
	}

	T&	operator[](std::size_t i)
	{
		if (i >= _size)
			throw Array::OutOfRangeException();
		return (_data[i]);
	}

	const T&	operator[](std::size_t i) const
	{
		if (i >= _size)
			throw Array::OutOfRangeException();
		return (_data[i]);
	}

	Array&	operator=(const Array& a)
	{
		if (this != &a)
		{
			if (_size)
			{
				delete[] _data;
				_data = NULL;
				_size = 0;
			}
			_size = a.size();
			if (_size)
				_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = a[i];
		}
		return (*this);
	}

	Array(void)
	: _size(0), _data(NULL) {}

	Array(unsigned int n)
	: _size(n), _data(NULL)
	{
		if (_size)
		_data = new T[_size];
	}

	Array(const Array& a)
	: _size(a.size()), _data(NULL)
	{
		if (_size)
			_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = a[i];
	}

	~Array(void)
	{
		if (_size)
		{
			delete[] _data;
			_data = NULL;
			_size = 0;
		}
	}
};

#endif
