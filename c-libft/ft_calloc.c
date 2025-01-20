/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:56:06 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/29 16:34:31 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(sizeof(char) * (count * size));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char*)ret)[i] = 0;
		++i;
	}
	return (ret);
}
