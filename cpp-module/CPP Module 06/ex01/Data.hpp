/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:51:35 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/01 20:08:47 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

/*
다음 함수를 구현하시오

1. uintptr_t serialize(Data* ptr);
이 함수는 포인터를 받아 unsigned int 타입의 uintptr_t로 변환해 줌

2. Data* deserialize(uintptr_t raw);
이 함수는 unsigned int를 받아 Data를 가리키는 포인터로 변환해 줌

두 함수가 잘 동작하는 것을 검증할 수 있는 프로그램을 작성하시오

non-empty인(data 멤버를 가진) Data structure를 만들어야 함
Data object의 주소를 serialize() 시킨 뒤 그 값을 deserialize()로 다시 되돌려 보시오
그 결과값을 원래 포인터 값과 비교해 일치하는지 확인해야 함

Data structure 파일을 제출하는 것을 잊지 마시오


static_cast와 reinterpret_cast의 차이
두 타입캐스팅은 대부분의 경우 비슷한 일은 수행하지만, static_cast는 reinterpret_cast보다 제한이 훨씬 많음
static_cast는 float에서 int로, base 클래스 포인터에서 derived 클래스 포인터로의 캐스트만을 허용함

reinterpret_cast는 모든 것을 허용하는데, 그렇기 때문에 위험하고 잘 사용되지 않음
전형적으로 포인터와 int간의 형변환에 쓰이고, 일부 로우 레벨 메모리 조작에 사용되기도 함
*/

class Data
{
private:
	int	data_;

public:
	int getData(void) const;

	Data&	operator=(const Data& d);
	Data();
	Data(const Data& d);
	Data(const int& data);
	~Data();
};

std::ostream&	operator<<(std::ostream& out, const Data& d);
uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif
