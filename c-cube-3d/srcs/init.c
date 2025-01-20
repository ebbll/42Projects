/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:13 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:17:30 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_info(t_info *info)
{
	info->screen_width = 0;
	info->screen_height = 0;
	info->map_width = 0;
	info->map_height = 0;
	info->map = NULL;
	info->north_texture_path = NULL;
	info->south_texture_path = NULL;
	info->west_texture_path = NULL;
	info->east_texture_path = NULL;
	info->sprite_texture_path = NULL;
	info->direction = 0;
	info->floor_color = 0;
	info->ceiling_color = 0;
	info->sprite_num = 0;
	info->buf = NULL;
	info->texture = NULL;
	info->player.pos_x = 0;
	info->player.pos_y = 0;
	info->player.dir_x = -1.0;
	info->player.dir_y = 0.0;
	info->player.plane_x = 0.0;
	info->player.plane_y = 0.66;
	info->player.move_speed = 0.05;
	info->player.rot_speed = 0.05;
}

void	init_cub_count(t_cub_count *cub_count)
{
	cub_count->r = 0;
	cub_count->no = 0;
	cub_count->so = 0;
	cub_count->we = 0;
	cub_count->ea = 0;
	cub_count->s = 0;
	cub_count->f = 0;
	cub_count->c = 0;
}

void	init_buffer(t_info *info)
{
	int	i;
	int	j;

	if (!(info->buf = (int **)malloc(sizeof(int *) * info->screen_height)))
		str_exit("Malloc has failed!\n");
	i = -1;
	while (++i < info->screen_height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * info->screen_width)))
			str_exit("Malloc has failed!\n");
	}
	i = -1;
	while (++i < info->screen_height)
	{
		j = -1;
		while (++j < info->screen_width)
			info->buf[i][j] = 0;
	}
	if (!(info->z_buf = (double *)malloc(sizeof(double) * info->screen_width)))
		str_exit("Malloc has failed!\n");
	i = -1;
	while (++i < info->screen_width)
		info->z_buf[i] = 0;
}

void	init_texture(t_info *info)
{
	int	i;
	int	j;

	if (!(info->texture = (int **)malloc(sizeof(int *) * 5)))
		str_exit("Malloc has failed!\n");
	i = -1;
	while (++i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) *
										(TEX_HEIGHT * TEX_WIDTH))))
			str_exit("Malloc has failed!\n");
	}
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			info->texture[i][j] = 0;
	}
}
