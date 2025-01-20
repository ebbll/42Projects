/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:33:21 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/16 17:03:36 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Replace
{
	private:
		static void	rpl(std::string *filenane,
						const std::string &s1,
						const std::string &s2);

		Replace(void);
		~Replace();

	public:
		static void	sed(const std::string &filename, 
						const std::string &s1,
						const std::string &s2);
};

#endif
