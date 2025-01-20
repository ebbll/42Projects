/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:19:54 by eunji             #+#    #+#             */
/*   Updated: 2021/02/18 20:15:27 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_info(t_info *info, char *line)
{
	t_list *lst;

	lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(info->fd, &line) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	free(line);
	close(info->fd);
	map_init(info, lst);
	map_fill(info, lst);
	ft_lstclear(&lst, free);
	set_sprite(info);
}

void	map_init(t_info *info, t_list *lst)
{
	int		i;
	int		j;

	info->map_height = ft_lstsize(lst);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->map_height))))
		str_exit("Malloc has failed!\n");
	i = 0;
	info->map_width = get_max_line_size(lst);
	while (lst)
	{
		if (!(info->map[i] = (char *)malloc(sizeof(char) *
										(info->map_width + 1))))
			str_exit("Malloc has failed!\n");
		j = 0;
		while (j++ < (int)ft_strlen((char *)lst->content))
			info->map[i][j] = 0;
		while (j++ < info->map_width)
			info->map[i][j] = ' ';
		info->map[i][info->map_width] = '\0';
		i++;
		lst = lst->next;
	}
}

void	map_fill(t_info *info, t_list *lst)
{
	int		i;
	int		j;
	char	*line;
	int		player_num;

	i = -1;
	player_num = 0;
	while (++i < info->map_height)
	{
		j = -1;
		line = (char *)lst->content;
		while (++j < (int)ft_strlen(line))
		{
			if (is_map_part(line[j]) == -1)
				str_exit("Unavailable character has found in the map!\n");
			info->map[i][j] = line[j];
			if (info->map[i][j] == '2')
				info->sprite_num++;
			set_player_location(info, i, j, &player_num);
		}
		lst = lst->next;
	}
	if (player_num == 0 || player_num > 1)
		str_exit("Number of players is not one!\n");
}

void	set_sprite(t_info *info)
{
	int	x;
	int y;
	int i;

	if (!(info->sprite = (t_sprite *)malloc(sizeof(t_sprite) *
							info->sprite_num)))
		str_exit("Malloc for sprite has failed!\n");
	i = 0;
	y = 0;
	while (y < info->map_height)
	{
		x = 0;
		while (x < info->map_width)
		{
			if (info->map[y][x] == '2')
			{
				info->sprite[i].x = 0.5f + y;
				info->sprite[i].y = 0.5f + x;
				i++;
			}
			x++;
		}
		y++;
	}
}
