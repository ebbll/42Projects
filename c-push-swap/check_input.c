/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:42:01 by eunlee            #+#    #+#             */
/*   Updated: 2021/10/12 12:08:36 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] == ' ')
			break ;
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_range(char *argv, int *ret)
{
	long long	convert;

	if (ft_wordlen(argv) > 11)
		return (0);
	convert = atolong(argv);
	if (convert < -2147483648 || convert > 2147483647)
		return (0);
	*ret = (int)convert;
	return (1);
}

int	check_input(t_stack *a, char **argv, t_info *info)
{
	int	value;

	if (check_valid(*argv) == 0)
		return (0);
	if (check_range(*argv, &value) == 0)
		return (0);
	if (check_dup(a, value) == 0)
		return (0);
	else
	{
		lstadd_back(a, value);
		info->len_a += 1;
	}
	*argv += ft_wordlen(*argv);
	return (1);
}
