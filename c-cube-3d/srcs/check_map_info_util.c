/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:49:18 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:09:22 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_top(t_info *info)
{
	int		j;

	j = 0;
	while (j < (int)ft_strlen(info->map[0]))
	{
		if (!(info->map[0][j] == ' ' || info->map[0][j] == '1'))
			str_exit("Top part of the map is wrong!\n");
		j++;
	}
}

void	check_map_left(t_info *info, int i, int j)
{
	while (info->map[i][j] == ' ')
		j++;
	if (info->map[i][j] != '1')
		str_exit("Left side of the map is wrong!\n");
}

void	check_map_right(t_info *info, int i, int j)
{
	if (info->map[i][j - 1] != '1')
		str_exit("Right side of the map is wrong!\n");
}

void	check_map_middle(t_info *info, int i, int j)
{
	if (0 < i && i < info->map_height - 1)
	{
		if (info->map[i - 1][j] == ' ' || info->map[i + 1][j] == ' ')
		{
			if (info->map[i][j] != ' ' && info->map[i][j] != '1')
				str_exit("Content of the map is wrong!\n");
		}
	}
	if (0 < j && j < info->map_width)
	{
		if (info->map[i][j - 1] == ' ' || info->map[i][j + 1] == ' ')
			if (info->map[i][j] != ' ' && info->map[i][j] != '1')
				str_exit("Content of the map is wrong!\n");
	}
}

void	check_map_bottom(t_info *info, int i)
{
	int j;

	j = 0;
	while (j < (int)ft_strlen(info->map[i]))
	{
		if (!(info->map[i][j] == ' ' || info->map[i][j] == '1'))
			str_exit("Bottom part of the map is wrong!\n");
		j++;
	}
}
