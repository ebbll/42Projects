/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:06:05 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/30 15:01:06 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

long long	atolong(char *str)
{
	int			i;
	long long	ret;

	i = 0;
	ret = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			break ;
		ret = 10 * ret + str[i++] - '0';
	}
	if (str[0] == '-')
		ret *= -1;
	return (ret);
}

int	check_dup(t_stack *a, int value)
{
	t_node	*temp;

	temp = a->head;
	if (!temp)
		return (1);
	while (temp)
	{
		if (temp->value == value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_order(t_stack *a)
{
	t_node	*temp;

	temp = a->head;
	if (temp == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_reorder(t_stack *a, t_stack *b, t_info *info, int range)
{
	t_node	*temp;

	temp = b->head;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	while (range--)
		ft_pa(a, b, info);
	return (1);
}
