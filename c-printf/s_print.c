/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:20:52 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/13 10:39:38 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		error_check(t_tag *tag)
{
	if (tag->flag_zero == 1)
	{
		tag->error = 1;
		return (1);
	}
	return (0);
}

void	s_process(char *s, t_tag *tag)
{
	int	i;
	int	len;

	i = 0;
	if (error_check(tag))
		return ;
	len = ft_strlen(s);
	if (tag->precision_point == 1 && tag->precision >= 0)
		if (tag->precision < len)
			len = tag->precision;
	if (tag->flag_minus == 0)
		put_space(tag->width - len);
	write(1, s, len);
	if (tag->flag_minus == 1)
		put_space(tag->width - len);
	tag->print_len = tag->width > len ? tag->width : len;
}

void	s_print(char *s, t_tag *tag)
{
	if (tag->width < 0)
	{
		tag->flag_minus = 1;
		tag->width *= -1;
	}
	if (s == 0)
		s = "(null)";
	s_process(s, tag);
	if (tag->error == 1)
		return ;
}
