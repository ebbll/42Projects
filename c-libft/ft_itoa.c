/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:50:46 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/29 13:48:28 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len(int n)
{
	int		ret;

	if (n == 0)
		return (1);
	ret = 0;
	if (n < 0)
		++ret;
	while (n != 0)
	{
		++ret;
		n /= 10;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;

	len = calc_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ret[len--] = '\0';
	if (n == 0)
		ret[0] = '0';
	else if (n < 0)
	{
		ret[0] = '-';
		ret[len--] = '0' + ((n % 10) * -1);
		n /= -10;
	}
	while (n != 0)
	{
		ret[len--] = '0' + n % 10;
		n /= 10;
	}
	return (ret);
}
