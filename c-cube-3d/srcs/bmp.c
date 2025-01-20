/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:52 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:02:07 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_int_to_char(unsigned char *array, int value)
{
	array[0] = (unsigned char)(value);
	array[1] = (unsigned char)(value >> 8);
	array[2] = (unsigned char)(value >> 16);
	array[3] = (unsigned char)(value >> 24);
}

void	bmp_header_set(t_info *info, int fd, int pad)
{
	unsigned char	header[54];
	int				size;

	size = 54 + ((info->screen_width * 3 + pad) * info->screen_height);
	ft_memset(header, 0, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	input_int_to_char(header + 2, size);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	input_int_to_char(header + 18, info->screen_width);
	input_int_to_char(header + 22, info->screen_height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	bmp_data_set(t_info *info, int fd, int pad)
{
	int					i;
	int					j;
	unsigned char		zero[3];

	i = -1;
	while (++i < 3)
		zero[i] = (unsigned char)0;
	i = info->screen_height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < info->screen_width)
		{
			write(fd, &(info->buf[i][j]), 3);
			j++;
		}
		write(fd, zero, pad);
		i--;
	}
}

void	bmp_save(t_info *info)
{
	int	fd;
	int	pad;

	pad = (4 - (info->screen_width * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 00755)) < 0)
		str_exit("Failed to open .bmp file!\n");
	bmp_header_set(info, fd, pad);
	bmp_data_set(info, fd, pad);
}
