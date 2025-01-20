/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:40:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/01 20:07:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <exception>
# include <ctime>

/*
오직 public virtual destructor만을 가진 Base 클래스를 구현하시오
이 Base 클래스를 상속받는 A, B, C 클래스를 구현하시오
(위 4개의 클래스는 Orthodox Canonical Form을 준수할 필요 없음)

다음 함수들을 구현하시오
1. Base * generate(void);
A, B, C 중 하나를 랜덤으로 인스턴스로 찍어낸 뒤, 이를 Base 포인터로 리턴해 줌
랜덤으로 하나를 정하는 방식은 자유롭게 생각해 보기

2. void identify(Base* p);
p가 가리키는 실제 객체의 타입이 무엇인지 출력해 줌 (A, B, C 중 하나가 출력될 것)

3. void identify(Base& p);
p가 가리키는 실제 객체의 타입이 무엇인지 출력해 줌 (A, B, C 중 하나가 출력될 것)
이 함수 내부에서 포인터를 사용하는 것은 금지됨

이 과제에서 typeinfo header를 사용하는 것은 금지됨

구현한 것이 제대로 작동하는 것을 검증할 수 있는 프로그램을 작성하시오


dynamic_cast<new_type>(expression)를 통해 다운캐스트 하려는 경우
우선 런타임중 expression과 new_type의 관계를 점검하는데,
expression이 다형성 추상 클래스(Base)이고, new_type이 이 Base의 파생 클래스인 경우에만 다운캐스팅 성공
만약 그렇지 않은 경우,
포인터의 경우엔 null이 리턴되고,
레퍼런스의 경우엔 std::bad_cast exception을 throw 함
*/

class Base
{
public:
	virtual ~Base(void);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
