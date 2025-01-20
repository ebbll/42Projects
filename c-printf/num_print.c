/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:50:53 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/13 10:44:29 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_process(t_tag *tag)
{
	if (tag->width < 0)
	{
		tag->flag_minus = 1;
		tag->width *= -1;
	}
	if (tag->flag_minus == 1 && tag->flag_zero == 1)
		tag->flag_zero = 0;
}

void	num_int_print(long long int num, int base, t_tag *tag)
{
	int	lowercase;
	int len;
	int space;

	lowercase = tag->specifier == 'x' ? 1 : 0;
	len = ft_intlen(num, base);
	space = tag->precision > len ? tag->precision : len;
	space = num < 0 ? (space + 1) : space;
	if (tag->flag_minus == 0 && tag->flag_zero == 0)
		put_space(tag->width - space);
	if (num < 0)
		write(1, "-", 1);
	if (tag->flag_zero == 1)
	{
		len = num < 0 ? (len + 1) : len;
		put_zero(tag->width - len);
	}
	else
		put_zero(tag->precision - len);
	ft_itoa(num, base, lowercase);
	if (tag->flag_minus == 1)
		put_space(tag->width - space);
	len = tag->flag_zero == 0 ? space : len;
	tag->print_len = tag->width > len ? tag->width : len;
}

void	num_print(long long int num, int base, t_tag *tag)
{
	num_process(tag);
	if (tag->error == 1)
		return ;
	if (tag->precision_point == 1 && tag->precision == 0 && num == 0)
	{
		tag->print_len = tag->width;
		put_space(tag->width);
		return ;
	}
	if (tag->precision < 0)
		tag->precision = 0;
	else if (tag->precision_point == 1 && tag->precision >= 0)
		tag->flag_zero = 0;
	num_int_print(num, base, tag);
}
