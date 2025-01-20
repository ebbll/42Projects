/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:00:23 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/13 10:40:09 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_tag(const char **format, t_tag *tag, va_list ap)
{
	tag_init(tag);
	*format += 1;
	check_flag(format, tag);
	check_width(format, tag);
	check_precision(format, tag);
	check_specifier(format, tag);
	if (tag->width_wildcard == 1)
		tag->width = va_arg(ap, int);
	if (tag->precision_wildcard == 1)
		tag->precision = va_arg(ap, int);
}

void	decide_arg(t_tag *tag, va_list ap)
{
	if (tag->specifier == 'c')
		c_print(va_arg(ap, int), tag);
	else if (tag->specifier == 's')
		s_print(va_arg(ap, char*), tag);
	else if (tag->specifier == 'p')
		p_print(va_arg(ap, long long int), tag);
	else if (tag->specifier == 'd' || tag->specifier == 'i')
		num_print(va_arg(ap, int), 10, tag);
	else if (tag->specifier == 'u')
		num_print(va_arg(ap, unsigned int), 10, tag);
	else if (tag->specifier == 'x' || tag->specifier == 'X')
		num_print(va_arg(ap, unsigned int), 16, tag);
	else if (tag->specifier == '%')
		percent_print(tag);
}

int		ft_printf(const char *format, ...)
{
	t_tag	tag;
	va_list ap;

	tag.ret = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			make_tag(&format, &tag, ap);
			if (tag.error)
				return (-1);
			decide_arg(&tag, ap);
			if (tag.error)
				return (-1);
			tag.ret += tag.print_len;
		}
		else
		{
			write(1, format++, 1);
			tag.ret++;
		}
	}
	va_end(ap);
	return (tag.ret);
}
