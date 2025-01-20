/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:57:22 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/30 14:19:08 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void stack_mem(void) {
	Bureaucrat a;
	Bureaucrat b;
	try {
		Bureaucrat c("bureaucrat_c", 100);
		a = c;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bureaucrat d("bureaucrat_d", 200);
		a = d;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

void heap_mem(void) {
	Bureaucrat *a = new Bureaucrat();
	try {
		Bureaucrat *b = new Bureaucrat("bureaucrat_b", 150);
		//use b
		try {
			b->decreaseGrade();
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		delete b;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << *a << std::endl;
	delete a;
}

int main(void) {
	stack_mem();
	std::cout << "=============================" << std::endl;
	heap_mem();
	return 0;
}