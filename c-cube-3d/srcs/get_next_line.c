/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:03 by eunji             #+#    #+#             */
/*   Updated: 2021/01/25 16:51:04 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join_free(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	free(s1);
	s1 = 0;
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	result[len] = '\0';
	return (result);
}

int		get_line(char *remainder, char **line, char *find_line)
{
	*line = ft_substr(remainder, 0, find_line - remainder);
	++find_line;
	ft_memmove(remainder, find_line, ft_strlen(find_line) + 1);
	return (1);
}

char	*read_line(int fd, char **line, char *remainder)
{
	char	*find_line;
	int		byte_num;
	char	buf[BUFFER_SIZE + 1];

	while (((byte_num = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[byte_num] = '\0';
		remainder = str_join_free(remainder, buf);
		if ((find_line = ft_strchr(remainder, '\n')))
		{
			get_line(remainder, line, find_line);
			return (remainder);
		}
	}
	if (remainder)
	{
		*line = ft_strdup(remainder);
		free(remainder);
		remainder = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*find_line;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (remainder && (find_line = ft_strchr(remainder, '\n')))
		return (get_line(remainder, line, find_line));
	if ((remainder = read_line(fd, line, remainder)))
		return (1);
	return (0);
}
