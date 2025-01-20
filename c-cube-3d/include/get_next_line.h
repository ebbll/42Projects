/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:11:24 by eunji             #+#    #+#             */
/*   Updated: 2021/01/23 15:13:26 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 32

char	*str_join_free(char *s1, char *s2);
int		get_line(char *remainder, char **line, char *find_line);
char	*read_line(int fd, char **line, char *remainder);
int		get_next_line(int fd, char **line);

#endif
