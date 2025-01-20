/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:33:46 by eunlee            #+#    #+#             */
/*   Updated: 2020/08/13 12:54:02 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rest_fd(int n, int fd)
{
	char	temp[10];
	int		i;

	i = 0;
	while (n > 0)
	{
		temp[i++] = n % 10 + '0';
		n /= 10;
	}
	i--;
	while (i >= 0)
		write(fd, &temp[i--], 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ft_rest_fd(n, fd);
}
