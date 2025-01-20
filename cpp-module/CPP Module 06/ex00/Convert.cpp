/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:48:40 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/04 14:38:09 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::printChar(void) const
{
	std::cout << "char: ";
	if (_state != FINE)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::numeric_limits<char>::max() >= _data &&
		std::numeric_limits<char>::min() <= _data)
	{
		char	c;
		c = static_cast<char>(_data);
		if (isprint(c))
		{
			std::cout << "'" << c << "'" << std::endl;
		}
		else
		{
			std::cout << "Non displayable" << std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	Convert::printInt(void) const
{
	std::cout << "int: ";
	if (_state != FINE) 
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::numeric_limits<int>::max() >= _data &&
		std::numeric_limits<int>::min() <= _data)
	{
		int	i;
		i = static_cast<int>(_data);
		std::cout << i << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	Convert::printFloat(void) const
{
	std::cout << "float: ";
	if (_state != FINE)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (std::isinf(_data))
	{
		std::cout << std::showpos << _data << "f" << std::endl;
		return ;
	}
	else if (std::isnan(_data))
	{
		std::cout << _data << "f" << std::endl;
		return ;
	}
	else if (_data == 0)
	{
		std::cout << "0.0f" << std::endl;
		return ;
	}
	if (std::numeric_limits<float>::max() >= _data &&
		std::numeric_limits<float>::min() <= _data)
	{
		float	f = static_cast<float>(_data);
		if (f == static_cast<int64_t>(f))
		{
			std::cout << f << ".0f" << std::endl;
		}
		else
		{
			std::cout << std::setprecision(std::numeric_limits<float>::digits10)
			<< f << "f" <<std::endl;
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	Convert::printDouble(void) const
{
	std::cout << "double: ";
	if (_state != FINE)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (std::isinf(_data))
	{
		std::cout << std::showpos << _data << std::endl;
		return ;
	}
	if (_data == static_cast<int64_t>(_data))
	{
		std::cout << _data << ".0" << std::endl;
	}
	else
	{
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << _data << std::endl;
	}
}

Convert& Convert::operator=(const Convert& c)
{
	_data = c._data;
	_str = c._str;
	_state = c._state;
	return (*this);
}

Convert::Convert(void) {}

Convert::Convert(const std::string& str)
: _data(0), _str(str), _state(FINE)
{
	char	*end = NULL;

	_data = std::strtod(str.c_str(), &end);
	if (errno == ERANGE)
	{
		_state = RANGE;
	}
	else if (str.c_str() == end)
	{
		_state = NODATA;
		if (str.size() == 1)
		{
			_state = FINE;
			_data = static_cast<double>(str[0]);
		}
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}

Convert::Convert(const Convert& c)
: _data(c._data), _str(c._str), _state(c._state) {}

Convert::~Convert() {}
