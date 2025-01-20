/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:55:19 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/15 15:06:14 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		std::string first_;
		std::string last_;
		std::string nickname_;
		std::string number_;
		std::string secret_;
		bool		CheckEmpty(std::string s) const;
	public:
		bool		CheckFirst() const;
		bool		CheckLast() const;
		bool		CheckNumber() const;
		void		GetNew();
		void		ReplaceField(Contact newcontact);
		std::string	CutString(std::string str);
		void		DisplayBriefly(int i);
		void		DisplayAll() const;
};

#endif
