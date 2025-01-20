/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:23 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:17:45 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_f_b(int key, t_info *info)
{
	if (key == K_W || key == K_AR_U)
	{
		if (info->map[(int)(info->player.pos_x + info->player.dir_x *
					info->player.move_speed)][(int)(info->player.pos_y)] != '1')
			info->player.pos_x += info->player.dir_x * info->player.move_speed;
		if (info->map[(int)(info->player.pos_x)][(int)(info->player.pos_y +
					info->player.dir_y * info->player.move_speed)] != '1')
			info->player.pos_y += info->player.dir_y * info->player.move_speed;
	}
	if (key == K_S || key == K_AR_D)
	{
		if (info->map[(int)(info->player.pos_x - info->player.dir_x *
					info->player.move_speed)][(int)(info->player.pos_y)] != '1')
			info->player.pos_x -= info->player.dir_x * info->player.move_speed;
		if (info->map[(int)(info->player.pos_x)][(int)(info->player.pos_y -
					info->player.dir_y * info->player.move_speed)] != '1')
			info->player.pos_y -= info->player.dir_y * info->player.move_speed;
	}
}

void	move_player_l_r(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->map[(int)(info->player.pos_x)][(int)(info->player.pos_y +
					info->player.dir_x * info->player.move_speed)] != '1')
			info->player.pos_y += info->player.dir_x * info->player.move_speed;
		if (info->map[(int)(info->player.pos_x - info->player.dir_y *
					info->player.move_speed)][(int)info->player.pos_y] != '1')
			info->player.pos_x -= info->player.dir_y * info->player.move_speed;
	}
	if (key == K_D)
	{
		if (info->map[(int)(info->player.pos_x)][(int)(info->player.pos_y -
					info->player.dir_x * info->player.move_speed)] != '1')
			info->player.pos_y -= info->player.dir_x * info->player.move_speed;
		if (info->map[(int)(info->player.pos_x + info->player.dir_y *
					info->player.move_speed)][(int)info->player.pos_y] != '1')
			info->player.pos_x += info->player.dir_y * info->player.move_speed;
	}
}

void	rotate_right_player(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir_x;
	old_plane_x = info->player.plane_x;
	info->player.dir_x = info->player.dir_x * cos(-info->player.rot_speed) -
						info->player.dir_y * sin(-info->player.rot_speed);
	info->player.dir_y = old_dir_x * sin(-info->player.rot_speed) +
						info->player.dir_y * cos(-info->player.rot_speed);
	info->player.plane_x = info->player.plane_x * cos(-info->player.rot_speed) -
							info->player.plane_y * sin(-info->player.rot_speed);
	info->player.plane_y = old_plane_x * sin(-info->player.rot_speed) +
							info->player.plane_y * cos(-info->player.rot_speed);
}

void	rotate_left_player(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->player.dir_x;
	old_plane_x = info->player.plane_x;
	info->player.dir_x = info->player.dir_x * cos(info->player.rot_speed) -
						info->player.dir_y * sin(info->player.rot_speed);
	info->player.dir_y = old_dir_x * sin(info->player.rot_speed) +
						info->player.dir_y * cos(info->player.rot_speed);
	info->player.plane_x = info->player.plane_x * cos(info->player.rot_speed) -
						info->player.plane_y * sin(info->player.rot_speed);
	info->player.plane_y = old_plane_x * sin(info->player.rot_speed) +
						info->player.plane_y * cos(info->player.rot_speed);
}

int		key_press(int key, t_info *info)
{
	if (key == K_W || key == K_AR_U)
		move_player_f_b(key, info);
	if (key == K_S || key == K_AR_D)
		move_player_f_b(key, info);
	if (key == K_A)
		move_player_l_r(key, info);
	if (key == K_D)
		move_player_l_r(key, info);
	if (key == K_AR_R)
		rotate_right_player(info);
	if (key == K_AR_L)
		rotate_left_player(info);
	if (key == K_ESC)
		exit(0);
	return (0);
}
