/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_info_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:50:12 by eunji             #+#    #+#             */
/*   Updated: 2021/01/25 16:50:14 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		digit_check(char **ptr)
{
	int	i;
	int	j;

	i = -1;
	while (ptr[++i])
	{
		j = -1;
		while (ptr[i][++j])
		{
			if (!ft_isdigit(ptr[i][j]))
				return (0);
		}
	}
	return (1);
}

int		check_digit_color(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = get_delete_space(ptr[i]);
		j = 0;
		while (ptr[i][j])
		{
			if (!ft_isdigit(ptr[i][j]))
				return (0);
			j++;
		}
		if ((0 > ft_atoi(ptr[i]) || ft_atoi(ptr[i]) > 255))
			return (0);
		i++;
	}
	return (1);
}

char	*get_delete_space(char *rgb)
{
	int	i;
	int index;

	i = 0;
	index = 0;
	while (rgb[i])
	{
		if (rgb[i] != ' ')
		{
			rgb[index] = rgb[i];
			index++;
		}
		i++;
	}
	rgb[index] = '\0';
	return (rgb);
}

int		search_format(char *file, char *format)
{
	int		file_len;
	int		format_len;
	char	*file_format;

	file = get_delete_space(file);
	file_len = ft_strlen(file);
	format_len = ft_strlen(format);
	if (file_len <= format_len)
		return (0);
	file_format = file + (file_len - format_len);
	if (!ft_strncmp(file_format, format, ft_strlen(file_format)))
		return (1);
	return (0);
}
