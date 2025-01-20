/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:47:07 by eunji             #+#    #+#             */
/*   Updated: 2021/02/22 16:01:00 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray_item(t_info *info, int x)
{
	info->ray.camera_x = 2 * x / (double)info->screen_width - 1;
	info->ray.dir_x = info->player.dir_x +
						info->player.plane_x * info->ray.camera_x;
	info->ray.dir_y = info->player.dir_y +
						info->player.plane_y * info->ray.camera_x;
	info->ray.map_x = (int)info->player.pos_x;
	info->ray.map_y = (int)info->player.pos_y;
	info->ray.delta_dist_x = fabs(1 / info->ray.dir_x);
	info->ray.delta_dist_y = fabs(1 / info->ray.dir_y);
	info->ray.hit = 0;
}

void	calc_step_direction(t_info *info)
{
	if (info->ray.dir_x < 0)
	{
		info->ray.step_x = -1;
		info->ray.side_dist_x = (info->player.pos_x - info->ray.map_x) *
								info->ray.delta_dist_x;
	}
	else
	{
		info->ray.step_x = 1;
		info->ray.side_dist_x = (info->ray.map_x + 1.0 - info->player.pos_x) *
								info->ray.delta_dist_x;
	}
	if (info->ray.dir_y < 0)
	{
		info->ray.step_y = -1;
		info->ray.side_dist_y = (info->player.pos_y - info->ray.map_y) *
								info->ray.delta_dist_y;
	}
	else
	{
		info->ray.step_y = 1;
		info->ray.side_dist_y = (info->ray.map_y + 1.0 - info->player.pos_y) *
								info->ray.delta_dist_y;
	}
}

void	perform_dda(t_info *info)
{
	while (info->ray.hit == 0)
	{
		if (info->ray.side_dist_x < info->ray.side_dist_y)
		{
			info->ray.side_dist_x += info->ray.delta_dist_x;
			info->ray.map_x += info->ray.step_x;
			if (info->ray.step_x == -1)
				info->ray.side = 0;
			else
				info->ray.side = 1;
		}
		else
		{
			info->ray.side_dist_y += info->ray.delta_dist_y;
			info->ray.map_y += info->ray.step_y;
			if (info->ray.step_y == -1)
				info->ray.side = 2;
			else
				info->ray.side = 3;
		}
		if (info->map[info->ray.map_x][info->ray.map_y] == '1')
			info->ray.hit = 1;
	}
}

void	calc_wall(t_info *info)
{
	if (info->ray.side <= 1)
		info->ray.perp_wall_dist = (info->ray.map_x - info->player.pos_x +
								(1 - info->ray.step_x) / 2) / info->ray.dir_x;
	else
		info->ray.perp_wall_dist = (info->ray.map_y - info->player.pos_y +
								(1 - info->ray.step_y) / 2) / info->ray.dir_y;
	info->ray.line_height = (int)(info->screen_height /
									info->ray.perp_wall_dist);
	info->ray.draw_start = -info->ray.line_height / 2 + info->screen_height / 2;
	if (info->ray.draw_start < 0)
		info->ray.draw_start = 0;
	info->ray.draw_end = info->ray.line_height / 2 + info->screen_height / 2;
	if (info->ray.draw_end >= info->screen_height)
		info->ray.draw_end = info->screen_height - 1;
}

void	calc_texture(t_info *info, int x)
{
	int	y;
	int	color;

	if (info->ray.side <= 1)
		info->ray.wall_x = info->player.pos_y + info->ray.perp_wall_dist
							* info->ray.dir_y;
	else
		info->ray.wall_x = info->player.pos_x + info->ray.perp_wall_dist
							* info->ray.dir_x;
	info->ray.wall_x -= floor(info->ray.wall_x);
	info->ray.tex_x = (int)(info->ray.wall_x * (double)TEX_WIDTH);
	if (info->ray.side == 1 || info->ray.side == 2)
		info->ray.tex_x = TEX_WIDTH - info->ray.tex_x - 1;
	info->ray.step = 1.0 * TEX_HEIGHT / info->ray.line_height;
	info->ray.tex_pos = (info->ray.draw_start - info->screen_height / 2 +
						info->ray.line_height / 2) * info->ray.step;
	y = info->ray.draw_start - 1;
	while (++y < info->ray.draw_end)
	{
		info->ray.tex_y = (int)info->ray.tex_pos & (TEX_HEIGHT - 1);
		info->ray.tex_pos += info->ray.step;
		color = info->texture[info->ray.side]
							[TEX_HEIGHT * info->ray.tex_y + info->ray.tex_x];
		info->buf[y][x] = color;
	}
}
