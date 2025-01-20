/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:23:42 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/14 12:30:25 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_process(t_tag *tag)
{
	if (tag->width < 0)
	{
		tag->flag_minus = 1;
		tag->width *= -1;
	}
	if (tag->flag_zero == 1)
		tag->error = 1;
	if (tag->precision_point == 1 && tag->no_precision == 0)
		tag->error = 1;
}

void	null_print(t_tag *tag)
{
	if (tag->width <= 2)
	{
		tag->print_len = 2;
		write(1, "0x", 2);
	}
	else
	{
		tag->print_len = tag->width;
		if (tag->flag_minus == 0)
			put_space(tag->width - 2);
		write(1, "0x", 2);
		if (tag->flag_minus == 1)
			put_space(tag->width - 2);
	}
}

void	p_print(long long int p, t_tag *tag)
{
	p_process(tag);
	if (tag->error == 1)
		return ;
	if (p == 0 && tag->precision_point == 1 && tag->no_precision == 1)
	{
		null_print(tag);
		return ;
	}
	if (tag->width <= ft_intlen(p, 16) + 2)
	{
		tag->print_len = ft_intlen(p, 16) + 2;
		write(1, "0x", 2);
		ft_itoa(p, 16, 1);
	}
	else
	{
		tag->print_len = tag->width;
		if (tag->flag_minus == 0)
			put_space(tag->width - (ft_intlen(p, 16) + 2));
		write(1, "0x", 2);
		ft_itoa(p, 16, 1);
		if (tag->flag_minus == 1)
			put_space(tag->width - (ft_intlen(p, 16) + 2));
	}
}
