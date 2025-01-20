/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:52:07 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:18:23 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_sprite(t_info *info)
{
	int		i;
	int		stripe;

	sort_sprite(info);
	i = 0;
	while (i < info->sprite_num)
	{
		translate_sprite(info, i);
		calc_sprite_height_width(info);
		stripe = info->ray_sprite.draw_start_x;
		while (stripe < info->ray_sprite.draw_end_x)
		{
			get_sprite(info, stripe);
			stripe++;
		}
		i++;
	}
}

void	calc_raycasting(t_info *info)
{
	int x;

	draw_floor_ceiling(info);
	x = 0;
	while (x < info->screen_width)
	{
		set_ray_item(info, x);
		calc_step_direction(info);
		perform_dda(info);
		calc_wall(info);
		calc_texture(info, x);
		info->z_buf[x] = info->ray.perp_wall_dist;
		x++;
	}
}

int		main_loop(t_info *info)
{
	calc_raycasting(info);
	calc_sprite(info);
	draw(info);
	return (0);
}
