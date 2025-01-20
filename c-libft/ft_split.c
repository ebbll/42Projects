/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:48:59 by eunlee            #+#    #+#             */
/*   Updated: 2020/08/13 17:01:14 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		arr_free(char **ret, int count)
{
	int i;

	i = 0;
	while (i < count)
		free(ret[i++]);
	free(ret);
}

static int	count_word(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

void		make_dup(char *dest, char const *src, int size)
{
	int i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	make_result(char const *s, char c, char **ret, int count)
{
	int		i;
	int		index;
	int		start;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ret[index] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (ret[index] == 0)
			{
				arr_free(ret, count);
				return (-1);
			}
			make_dup(ret[index++], &s[start], i - start);
		}
		else
			i++;
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		count;

	count = count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (ret == 0)
		return (NULL);
	if (make_result(s, c, ret, count) == -1)
		return (NULL);
	ret[count] = 0;
	return (ret);
}
