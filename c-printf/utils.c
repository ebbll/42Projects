/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:26:45 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/14 12:31:24 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		++str;
		++i;
	}
	return (i);
}

int		ft_intlen(long long int n, int base)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

void	put_space(int n)
{
	if (n <= 0)
		return ;
	while (0 < n--)
		write(1, " ", 1);
}

void	put_zero(int n)
{
	if (n <= 0)
		return ;
	while (0 < n--)
		write(1, "0", 1);
}

void	ft_itoa(long long int n, int base, int lower)
{
	int		i;
	char	ret[100];
	char	*num;

	if (n == 0)
		write(1, &"0", 1);
	if (n < 0)
		n *= -1;
	i = 0;
	if (lower == 1)
		num = "0123456789abcdef";
	else if (lower == 0)
		num = "0123456789ABCDEF";
	while (n != 0)
	{
		ret[i] = num[n % base];
		n /= base;
		++i;
	}
	--i;
	while (i >= 0)
	{
		write(1, &ret[i], 1);
		--i;
	}
}
