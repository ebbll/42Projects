/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:07:38 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/29 15:02:51 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	check_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (-1);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		ret;
	int		neg;

	ret = 0;
	neg = 1;
	i = 0;
	while (check_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (check_num(str[i]) != -1)
	{
		ret = 10 * ret + check_num(str[i]);
		i++;
	}
	return (ret * neg);
}
