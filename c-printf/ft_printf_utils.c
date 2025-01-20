/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:34:49 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/14 12:30:01 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tag_init(t_tag *tag)
{
	tag->error = 0;
	tag->flag_minus = 0;
	tag->flag_zero = 0;
	tag->width_wildcard = 0;
	tag->width = 0;
	tag->precision_wildcard = 0;
	tag->precision_point = 0;
	tag->precision = 0;
	tag->no_precision = 1;
	tag->specifier = 0;
	tag->print_len = 0;
}

void	check_flag(const char **format, t_tag *tag)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			tag->flag_minus = 1;
		if (**format == '0')
			tag->flag_zero = 1;
		(*format)++;
	}
}

void	check_width(const char **format, t_tag *tag)
{
	int		width;

	if (**format == '*')
	{
		tag->width_wildcard = 1;
		(*format)++;
		return ;
	}
	width = 0;
	while (**format >= '0' && **format <= '9')
	{
		width = width * 10 + **format - '0';
		(*format)++;
	}
	tag->width = width;
}

void	check_precision(const char **format, t_tag *tag)
{
	if (**format != '.')
		return ;
	tag->precision_point = 1;
	(*format)++;
	if (**format == '*')
	{
		tag->precision_wildcard = 1;
		tag->no_precision = 0;
		(*format)++;
		return ;
	}
	if (!(**format >= '0' && **format <= '9'))
		return ;
	while (**format >= '0' && **format <= '9')
	{
		tag->precision = tag->precision * 10 + **format - '0';
		(*format)++;
	}
	tag->no_precision = 0;
}

void	check_specifier(const char **format, t_tag *tag)
{
	if (**format == 'c')
		tag->specifier = 'c';
	else if (**format == 's')
		tag->specifier = 's';
	else if (**format == 'p')
		tag->specifier = 'p';
	else if (**format == 'd')
		tag->specifier = 'd';
	else if (**format == 'i')
		tag->specifier = 'i';
	else if (**format == 'u')
		tag->specifier = 'u';
	else if (**format == 'x')
		tag->specifier = 'x';
	else if (**format == 'X')
		tag->specifier = 'X';
	else if (**format == '%')
		tag->specifier = '%';
	else
		tag->error = 1;
	(*format)++;
}
