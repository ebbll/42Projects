/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:33:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/17 20:54:43 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	Replace::rpl(std::string *str,
					const std::string &s1,
					const std::string &s2)
{
	std::size_t index = 0;
	while (true) {
		index = (*str).find(s1, index);
		if (index == std::string::npos)
			break ;
		std::string former = (*str).substr(0, index);
		former += s2;
		std::string latter = (*str).substr(index + s1.length());
		index += s2.length();
		(*str) = former + latter;
	}
}

void	Replace::sed(const std::string &filename, 
					const std::string &s1,
					const std::string &s2)
{
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "usage: ./Replace [filename] [s1] [s2]" << std::endl;
		return ;
	}
	std::ifstream in(filename, std::ifstream::in);
	if (!in.is_open())
	{
		std::cout << "File open failed" << std::endl;
		return ;
	}
	std::ostringstream sbuf;
	sbuf << in.rdbuf();
	std::string temp = sbuf.str();
	in.close();
	Replace::rpl(&temp, s1, s2);
	std::ofstream out(filename + ".replace",
					std::ofstream::out | std::ofstream::trunc);
	if (!out.is_open())
	{
		std::cout << "File create failed" << std::endl;
		return ;
	}
	out << temp;
	out.close();
}

Replace::Replace(void)
{

}

Replace::~Replace()
{
	
}
