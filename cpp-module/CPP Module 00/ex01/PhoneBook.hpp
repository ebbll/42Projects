/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:19:40 by eunlee            #+#    #+#             */
/*   Updated: 2022/03/12 19:48:39 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact 	book[8];
		Contact		newcontact;
		static int	count_;
		static int	oldest_;
	public:
		void		AddPhoneBook();
		void		SearchPhoneBook();
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
