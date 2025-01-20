/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:59 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/16 16:49:51 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "usage: ./Replace [filename] [s1] [s2]" << std::endl;
	else
		Replace::sed(argv[1], argv[2], argv[3]);
	return (0);
}
