/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:50:50 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:16:21 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_direction(t_player *player, double radian)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = tmp_dir_x * cos(radian) - player->dir_y * sin(radian);
	player->dir_y = tmp_dir_x * sin(radian) + player->dir_y * cos(radian);
	tmp_plane_x = player->plane_x;
	player->plane_x = tmp_plane_x * cos(radian) - player->plane_y * sin(radian);
	player->plane_y = tmp_plane_x * sin(radian) + player->plane_y * cos(radian);
}

void	set_player_location(t_info *info, int i, int j, int *player_num)
{
	int	degree;

	degree = 0;
	if (is_direction_part(info->map[i][j]) == 1)
	{
		info->player.pos_x = 0.5f + i;
		info->player.pos_y = 0.5f + j;
		(*player_num)++;
		info->direction = info->map[i][j];
		if (info->direction == 'W')
			degree = 0;
		else if (info->direction == 'S')
			degree = 90;
		else if (info->direction == 'E')
			degree = 180;
		else if (info->direction == 'N')
			degree = 270;
		set_player_direction(&info->player, degree * (PI / 180));
	}
}

int		get_max_line_size(t_list *lst)
{
	int		result;
	int		size;

	result = 0;
	while (lst)
	{
		size = ft_strlen((char *)lst->content);
		if (result < size)
			result = size;
		lst = lst->next;
	}
	return (result);
}

int		is_map_part(int c)
{
	if (is_direction_part(c) == 1 || c == ' ' ||
		('0' <= c && c <= '2') || c == '\n' || c == '\0')
		return (1);
	return (-1);
}

int		is_direction_part(int c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	return (-1);
}
