/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:36 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:17:59 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
										&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
										&img->size_line, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->west_texture_path, &img);
	load_image(info, info->texture[1], info->east_texture_path, &img);
	load_image(info, info->texture[2], info->south_texture_path, &img);
	load_image(info, info->texture[3], info->north_texture_path, &img);
	load_image(info, info->texture[4], info->sprite_texture_path, &img);
	ft_free(info->north_texture_path);
	ft_free(info->south_texture_path);
	ft_free(info->west_texture_path);
	ft_free(info->east_texture_path);
	ft_free(info->sprite_texture_path);
}
