/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:42:34 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/13 10:37:24 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_process(t_tag *tag)
{
	if (tag->width < 0)
	{
		tag->flag_minus = 1;
		tag->width *= -1;
	}
	if (tag->flag_zero == 1 && tag->flag_minus == 1)
		tag->flag_zero = 0;
	tag->print_len = tag->width > 1 ? tag->width : 1;
}

void	percent_print(t_tag *tag)
{
	percent_process(tag);
	if (tag->error == 1)
		return ;
	if (tag->flag_minus == 0)
	{
		if (tag->flag_zero == 0)
			put_space(tag->print_len - 1);
		else if (tag->flag_zero == 1)
			put_zero(tag->print_len - 1);
	}
	write(1, "%", 1);
	if (tag->flag_minus == 1)
		put_space(tag->print_len - 1);
}
