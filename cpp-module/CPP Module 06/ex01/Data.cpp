/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:51:38 by eunlee            #+#    #+#             */
/*   Updated: 2022/04/01 18:43:22 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	Data::getData(void) const
{
	return data_;
}

Data& Data::operator=(const Data& d) {
	data_ = d.data_;
	return *this;
}

Data::Data(void)
: data_(0) {}

Data::Data(const int& data) : data_(data) {}

Data::Data(const Data& d) : data_(d.data_) {}

Data::~Data() {}

std::ostream&	operator<<(std::ostream& out, const Data& d) {
	out << "data : " << d.getData() << std::endl;
	return (out);
}

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
