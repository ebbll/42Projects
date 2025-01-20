/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:28:14 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 16:34:07 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	mutantTest(void)
{
	std::cout << "MUTANT STACK TEST" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "======================" << std::endl;
	std::cout << "iterator" << std::endl;
	int tmp = *it;
	*it = 42;
	*it = tmp;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	++cit;
	--cit;
	std::cout << "======================" << std::endl;
	std::cout << "const_iterator" << std::endl;
	tmp = *cit;
	// *cit = 42;
	// *cit = tmp;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	std::cout << "======================" << std::endl;
	std::cout << "reverse_iterator" << std::endl;
	tmp = *rit;
	*rit = 42;
	*rit = tmp;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.crend();
	++crit;
	--crit;
	std::cout << "======================" << std::endl;
	std::cout << "const_reverse_iterator" << std::endl;

	tmp = *crit;
	// *crit = 42;
	// *crit = tmp;
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	std::stack<int> s(mstack);
}

void	listTest(void)
{
	std::cout << "\nLIST TEST" << std::endl;
	std::list<int>	list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	std::cout << "======================" << std::endl;
	std::cout << "iterator" << std::endl;
	int tmp = *it;
	*it = 42;
	*it = tmp;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> l(list);
}

int main(void)
{
	mutantTest();
	listTest();

	return 0;
}
