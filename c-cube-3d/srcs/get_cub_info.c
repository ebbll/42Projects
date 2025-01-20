/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:49:58 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:13:54 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub_info_read(t_info *info, char *line, t_cub_count *cub_count)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		get_screen_size(info, ++cub_count->r, line + 2);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(info, ++cub_count->no, line + 3, "NO");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(info, ++cub_count->so, line + 3, "SO");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(info, ++cub_count->we, line + 3, "WE");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(info, ++cub_count->ea, line + 3, "EA");
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(info, ++cub_count->s, line + 2, "S");
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(info, ++cub_count->f, line + 2, 'F');
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(info, ++cub_count->c, line + 2, 'C');
	else if (line[0] == '\0')
		return (0);
	else
		return (-1);
	return (0);
}

void	get_screen_size(t_info *info, int count, char *line)
{
	char	**size;

	if (count != 1)
		str_exit("Number of identifiers not 1!\n");
	if (!(size = ft_split(line, ' ')))
		str_exit("Resolution split Failure!\n");
	if (!size[0] || !size[1] || size[2])
		str_exit("Resolution information is invalid!\n");
	if (!digit_check(size))
		str_exit("Non-numeric values exist in resolution!\n");
	info->screen_width = ft_atoi(size[0]);
	info->screen_height = ft_atoi(size[1]);
	free_double_ptr(size);
	if (info->screen_width > 2560)
		info->screen_width = 2560;
	if (info->screen_height > 1440)
		info->screen_height = 1440;
	if (info->screen_width < 848)
		info->screen_width = 848;
	if (info->screen_height < 400)
		info->screen_height = 400;
	if (!info->screen_width || !info->screen_height)
		str_exit("Resolution information is invalid!\n");
}

void	get_texture(t_info *info, int count, char *path, char *comp)
{
	int	fd;

	if (count != 1)
		str_exit("Number of identifiers not 1!\n");
	path = get_delete_space(path);
	if (!path || !search_format(path, ".xpm"))
		str_exit(".xpm file does not exist!\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		str_exit("Check the .xpm file path!\n");
	close(fd);
	if (comp[0] == 'N' && comp[1] == 'O')
		info->north_texture_path = ft_strdup(path);
	else if (comp[0] == 'S' && comp[1] == 'O')
		info->south_texture_path = ft_strdup(path);
	else if (comp[0] == 'W' && comp[1] == 'E')
		info->west_texture_path = ft_strdup(path);
	else if (comp[0] == 'E' && comp[1] == 'A')
		info->east_texture_path = ft_strdup(path);
	else if (comp[0] == 'S' && comp[1] == '\0')
		info->sprite_texture_path = ft_strdup(path);
	else
		str_exit("Check the identifier!\n");
}

void	get_color(t_info *info, int count, char *line, int comp)
{
	char	**rgb;
	int		color;

	if (count != 1)
		str_exit("Number of identifiers is not one and only!\n");
	if (!(rgb = ft_split(line, ',')))
		str_exit("RGB value split has failed!\n");
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		str_exit("RGB values are wrong!\n");
	if (!check_digit_color(rgb))
		str_exit("RGB value is not digital!\n");
	color = ((ft_atoi(rgb[0]) * 256) + ft_atoi(rgb[1])) * 256 + ft_atoi(rgb[2]);
	free_double_ptr(rgb);
	rgb = 0;
	if (comp == 'F')
		info->floor_color = color;
	else if (comp == 'C')
		info->ceiling_color = color;
}

void	get_cub_info(t_info *info, t_cub_count *cub_count)
{
	char	*line;
	int		ret;

	init_info(info);
	init_cub_count(cub_count);
	info->mlx = mlx_init();
	while (get_next_line(info->fd, &line) > 0)
	{
		if ((ret = cub_info_read(info, line, cub_count)) == 0)
			free(line);
		else if (ret == -1)
			break ;
	}
	info->line = line;
}
