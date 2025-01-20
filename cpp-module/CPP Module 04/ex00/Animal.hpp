/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:44 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/28 16:37:11 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

/*
Polymorphism: 다형성

모든 동작을 테스트 할 수 있을만한 테스트 코드를 함께 제출하시오

생성자와 소멸자는 메시지를 출력함
클래스마다 메시지를 다르게 출력하도록 해야 함

우선 Animal이라는 기반 클래스를 만드시오
아래와 같은 protected attribute를 가짐
	• std::string type;

Animal을 상속하는 클래스 Dog을 만드시오
Animal을 상속하는 클래스 Cat을 만드시오

두 파생 클래스는 그들의 name에 따라 type 필드를 설정해야 함
그리고 나서, Dog의 type은 "Dog"으로, Cat의 type은 "Cat"으로 초기화 됨
Animal 클래스의 type은 비워두워도 되고 값을 갖도록 해도 됨

모든 동물들은 아래와 같은 멤버 함수를 실행할 수 있어야 함
makeSound()
이 함수는 적절한 소리를 출력함 (cat은 "멍멍" 하지 않음)
주어진 메인문을 실행하면 Dog과 Cat 클래스에 걸맞는 사운드를 출력해야 함 (Animal의 소리가 아님)
(은지생각) const Animal* j = new Dog(); 이렇게 담아도 Animal이 아니라 Dog과 Cat으로 찾아가서 makeSound() 호출해야 한다는 의미인듯?

이 부분을 이해했다는 걸 증명하기 위해, 잘못된 코드를 구현해 대비시켜 봐야 함
WrongCat 클래스를 구현하고, 그것이 WrongAnimal class를 상속받게 하시오
Animal과 Cat의 관계를 잘못되게 만들고 나면, WrongCat의 makeSound()는 WrongAnimal의 사운드를 출력하게 될 것임

구현을 끝내면 주어진 메인문에 내용을 더 추가해서 제출
*/

class Animal
{
protected:
	std::string	_type;

public:
	virtual std::string	getType() const;
	virtual void	makeSound() const;

	Animal&	operator=(const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();
};

#endif
