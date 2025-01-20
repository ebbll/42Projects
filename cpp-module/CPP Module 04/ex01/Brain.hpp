/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:11:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/27 14:31:47 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
각 클래스의 생성자와 소멸자는 서로 다른 메시지를 출력해야 함

Brain 클래스를 구현하시오
std::string 100개를 담는 array를 갖고 있으며, 이것의 이름은 ideas
이런 식으로, Dog과 Cat은 private Brain* attribute를 갖게 됨
생성자에서 Dog과 Cat은 'new Brain()'을 통해 Brain을 생성함
소멸자에서 Dog과 Cat은 'delete Brain'을 함

메인 함수에서 Animal 객체의 배열을 만드시오
배열의 절반은 Dog 객체가, 나머지 절반은 Cat 객체가 됨
프로그램 실행이 종료될 때, array를 루프로 순회하면서 모든 Animal을 delete 해야 함

dog과 cat들을 Animal로 직접 delete 해야 함
예상되는 순서대로 소멸자가 적절하게 호출되어야 함

메모리 릭 체크 해야 함

Dog과 Cat의 복사는 깊은 복사여야 함 - 깊은 복사임을 테스트로 보여줘야 함
주어진 메인문에 테스트를 더하여 제출
*/

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
private:
	std::string	_ideas[100];
public:
	std::string	getIdea(const int i) const;
	void	setIdea(const int i, const std::string newIdea);

	Brain&	operator=(const Brain &b);
	Brain(void);
	Brain(const Brain &b);
	virtual ~Brain();
};

#endif
