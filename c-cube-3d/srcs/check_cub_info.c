/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:47:59 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:06:44 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub_info(t_info *info, t_cub_count *cub_count)
{
	if (!info->screen_width || !info->screen_height)
		str_exit("Resoulution values are wrong!\n");
	if (!info->north_texture_path ||
		!info->south_texture_path ||
		!info->west_texture_path ||
		!info->east_texture_path ||
		!info->sprite_texture_path)
		str_exit("Texture pathes are wrong!\n");
	if (!info->floor_color || !info->ceiling_color)
		str_exit("RGB values are wrong!\n");
	if (cub_count->r != 1 || cub_count->no != 1 ||
		cub_count->so != 1 || cub_count->we != 1 ||
		cub_count->ea != 1 || cub_count->s != 1 ||
		cub_count->f != 1 || cub_count->c != 1)
		str_exit("Number of identifiers not one and only!\n");
}
