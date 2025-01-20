/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:38:05 by eunlee            #+#    #+#             */
/*   Updated: 2020/08/13 12:43:39 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	ret = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (ret);
	while (src[i])
	{
		if (i >= dstsize - 1)
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ret);
}
