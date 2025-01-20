/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:31:41 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 14:53:29 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

/*
함수 템플릿 iter를 구현하시오
iter는 3개의 인자를 받고, 아무 것도 리턴하지 않음

• 첫 번째 인자: array의 주소
• 두 번째 인자: array의 length
• 세 번째 인자: array의 모든 element에 적용될 함수

테스트 코드를 main.cpp 파일에 작성하여 제출하시오
적용해 볼 수 있는 테스트를 충분히 만들어 보시오

구현한 함수 템플릿 iter는 어떤 타입의 array든 실행 가능해야 함
세 번째 인자는 함수 템플릿의 인스턴스를 넣어도 됨
*/

template <typename T>
void	iter(T *arr, unsigned int length, void (*f)(const T &))
{
	for (unsigned int i = 0; i < length; ++i)
	{
		f(arr[i]);
	}
}

#endif
