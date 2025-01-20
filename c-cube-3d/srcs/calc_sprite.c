/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:47:22 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:04:45 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprite(t_info *info)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < info->sprite_num)
	{
		info->sprite[i].distance = ((info->player.pos_x - info->sprite[i].x) *
			(info->player.pos_x - info->sprite[i].x) + (info->player.pos_y -
			info->sprite[i].y) * (info->player.pos_y - info->sprite[i].y));
	}
	i = -1;
	while (++i < info->sprite_num - 1)
	{
		j = -1;
		while (++j < info->sprite_num - 1 - i)
		{
			if (info->sprite[j].distance < info->sprite[j + 1].distance)
			{
				temp = info->sprite[j];
				info->sprite[j] = info->sprite[j + 1];
				info->sprite[j + 1] = temp;
			}
		}
	}
}

void	translate_sprite(t_info *info, int i)
{
	info->ray_sprite.relative_dist_x = info->sprite[i].x - info->player.pos_x;
	info->ray_sprite.relative_dist_y = info->sprite[i].y - info->player.pos_y;
	info->ray_sprite.inverse_determinant = 1.0 /
					(info->player.dir_y * info->player.plane_x -
					info->player.dir_x * info->player.plane_y);
	info->ray_sprite.trans_x = info->ray_sprite.inverse_determinant *
					(info->player.dir_y * info->ray_sprite.relative_dist_x -
					info->player.dir_x * info->ray_sprite.relative_dist_y);
	info->ray_sprite.trans_y = info->ray_sprite.inverse_determinant *
					(-info->player.plane_y * info->ray_sprite.relative_dist_x +
					info->player.plane_x * info->ray_sprite.relative_dist_y);
	info->ray_sprite.screen_x = (int)((info->screen_width / 2) *
				(1 + info->ray_sprite.trans_x / info->ray_sprite.trans_y));
}

void	calc_sprite_height_width(t_info *info)
{
	info->ray_sprite.height = abs((int)(info->screen_height /
								info->ray_sprite.trans_y));
	info->ray_sprite.draw_start_y = -info->ray_sprite.height / 2 +
									info->screen_height / 2;
	if (info->ray_sprite.draw_start_y < 0)
		info->ray_sprite.draw_start_y = 0;
	info->ray_sprite.draw_end_y = info->ray_sprite.height / 2 +
								info->screen_height / 2;
	if (info->ray_sprite.draw_end_y >= info->screen_height)
		info->ray_sprite.draw_end_y = info->screen_height - 1;
	info->ray_sprite.width = abs((int)(info->screen_height /
								info->ray_sprite.trans_y));
	info->ray_sprite.draw_start_x = -info->ray_sprite.width / 2 +
									info->ray_sprite.screen_x;
	if (info->ray_sprite.draw_start_x < 0)
		info->ray_sprite.draw_start_x = 0;
	info->ray_sprite.draw_end_x = info->ray_sprite.width / 2 +
								info->ray_sprite.screen_x;
	if (info->ray_sprite.draw_end_x >= info->screen_width)
		info->ray_sprite.draw_end_x = info->screen_width - 1;
}

void	get_sprite(t_info *info, int sprite)
{
	int	draw;
	int	color;
	int	y;

	info->ray_sprite.tex_x = (int)((256 * (sprite - (-info->ray_sprite.width /
							2 + info->ray_sprite.screen_x)) *
							TEX_WIDTH / info->ray_sprite.width) / 256);
	if (info->ray_sprite.trans_y > 0 && sprite > 0 &&
		sprite < info->screen_width &&
		info->ray_sprite.trans_y < info->z_buf[sprite])
	{
		y = info->ray_sprite.draw_start_y;
		while (y < info->ray_sprite.draw_end_y)
		{
			draw = y * 256 - info->screen_height * 128 +
					info->ray_sprite.height * 128;
			info->ray_sprite.tex_y = ((draw * TEX_HEIGHT) /
									info->ray_sprite.height) / 256;
			color = info->texture[4][TEX_WIDTH * info->ray_sprite.tex_y +
									info->ray_sprite.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				info->buf[y][sprite] = color;
			y++;
		}
	}
}
