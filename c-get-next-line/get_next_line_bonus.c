/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:59:52 by eunlee            #+#    #+#             */
/*   Updated: 2020/11/05 17:39:51 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split_newline(char **backup, char **line, int i)
{
	char	*temp;
	int		len;

	(*backup)[i] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + i + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + i + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		end_file(char **backup, char **line, int read_size)
{
	int		i;

	if (read_size < 0)
		return (-1);
	if (*backup && (i = check_newline(*backup)) >= 0)
		return (split_newline(backup, line, i));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			i;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((i = check_newline(backup[fd])) >= 0)
			return (split_newline(&backup[fd], line, i));
	}
	return (end_file(&backup[fd], line, read_size));
}
