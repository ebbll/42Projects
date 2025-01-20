/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:16:09 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/14 12:28:51 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_process(t_tag *tag)
{
	if (tag->width < 0)
	{
		tag->flag_minus = 1;
		tag->width *= -1;
	}
	if ((tag->flag_zero == 1) ||
		(tag->precision_point == 1 && tag->no_precision == 0))
	{
		tag->error = 1;
		return ;
	}
	tag->print_len = tag->width > 1 ? tag->width : 1;
}

void	c_print(int c, t_tag *tag)
{
	int i;

	i = 0;
	c_process(tag);
	if (tag->error == 1)
		return ;
	if (tag->flag_minus == 0)
		put_space(tag->print_len - 1);
	write(1, &c, 1);
	if (tag->flag_minus == 1)
		put_space(tag->print_len - 1);
}
