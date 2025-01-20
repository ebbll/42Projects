/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:02:24 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/05 17:49:50 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <vector>
#include <iostream>

unsigned int	Span::getElementCount(void) const
{
	return (_data.size());
}

unsigned int	Span::getSize(void) const
{
	return (_size);
}

void	Span::addNumber(const int &value)
{
	if (_data.size() >= _size)
		throw FullException();
	_data.push_back(value);
}

unsigned int	Span::shortestSpan(void)
{
	if (_data.size() <= 1)
		throw LackException();
	std::vector<long> calc(_data.begin(), _data.end());
	std::sort(calc.begin(), calc.end());
	std::adjacent_difference(calc.begin(), calc.end(), calc.begin());
	unsigned int	ret = *std::min_element(calc.begin() + 1, calc.end());
	return ret;
}

unsigned int	Span::longestSpan(void)
{
	if (_data.size() <= 1)
		throw LackException();
	int	max = *std::max_element(_data.begin(), _data.end());
	int	min = *std::min_element(_data.begin(), _data.end());
	// std::cout << "max: " << max << std::endl;
	// std::cout << "min: " << min << std::endl;
	unsigned int	ret = max - min;
	return (ret);
}

void	Span::generateNumbers(const unsigned int &count)
{
	if (count > _size)
		throw ExceedSizeException();
	std::vector<int>	randGen;
	srand(time(NULL));
	for (unsigned int i = 0; i < count; ++i)
	{
		int	value = rand() % INT_MAX;
		randGen.push_back(value);
	}
	_data.clear();
	_data = std::vector<int>(randGen.begin(), randGen.end());
}

void	Span::displaySpan(void)
{
	std::cout << "Display Span" << std::endl;
	for (std::vector<int>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		std::cout << "    " << *it << std::endl;
	}
}

Span&	Span::operator=(const Span &s)
{
	*const_cast<unsigned int*>(&_size) = s._size;
	_data.clear();
	_data = s._data;
	return (*this);
}

Span::Span(unsigned int N)
: _size(N) {}

Span::Span(const Span &s)
: _size(s._size)
{
	_data.clear();
	_data = s._data;
}

Span::~Span() {}
