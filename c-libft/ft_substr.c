/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:44:07 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/29 16:52:55 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valid_len(char const *s, unsigned int start, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (s[start + i] == 0)
			break ;
		i++;
	}
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub;

	l = valid_len(s, start, len);
	sub = (char *)malloc(sizeof(char) * (l + 1));
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (i < l)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
