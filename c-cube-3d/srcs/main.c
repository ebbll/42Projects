/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:57 by eunji             #+#    #+#             */
/*   Updated: 2021/02/22 15:39:53 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arguments(int argc, char *option, int *save_option)
{
	if (argc < 2)
		str_exit("argc > 2!\n");
	if (argc > 3)
		str_exit("Arguments given too many!\n");
	if (argc == 2)
		*save_option = FALSE;
	else if (!ft_strncmp(option, "--save", ft_strlen(option)))
		*save_option = TRUE;
	else
		str_exit("Argument is invalid!\n");
}

void	open_cub(char *file, t_info *info)
{
	if (!search_format(file, ".cub"))
		str_exit("Insert the .cub file!\n");
	info->fd = open(file, O_RDONLY);
	if (info->fd == -1)
		str_exit("Failed to open .cub file!\n");
}

void	start_raycasting(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->screen_width,
								info->screen_height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, info->screen_width,
								info->screen_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
						&info->img.bits_per_pixel, &info->img.size_line,
						&info->img.endian);
	mlx_loop_hook(info->mlx, main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
	mlx_loop(info->mlx);
}

void	get_bmp(t_info *info)
{
	calc_raycasting(info);
	calc_sprite(info);
	bmp_save(info);
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_info			info;
	t_cub_count		cub_count;
	int				save_option;

	check_arguments(argc, argv[2], &save_option);
	open_cub(argv[1], &info);
	get_cub_info(&info, &cub_count);
	check_cub_info(&info, &cub_count);
	get_map_info(&info, info.line);
	check_map_info(&info);
	init_buffer(&info);
	init_texture(&info);
	load_texture(&info);
	if (save_option == 1)
		get_bmp(&info);
	else
		start_raycasting(&info);
	all_free(&info);
	return (0);
}
