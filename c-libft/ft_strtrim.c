/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:38:23 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/30 12:14:49 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	calc_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (check_trim(s1[i], set) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	calc_end(char const *s1, char const *set)
{
	int		i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (check_trim(s1[i], set) == 0)
			break ;
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = calc_start(s1, set);
	end = calc_end(s1, set);
	if (start < end)
		ret = (char *)malloc(sizeof(char) * (end - start + 2));
	else
		ret = (char *)malloc(sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}
