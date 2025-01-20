/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <eunji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:17:42 by eunlee            #+#    #+#             */
/*   Updated: 2021/10/27 16:20:53 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	under2(t_stack *a, t_info *info)
{
	if (a->head->value > a->head->next->value)
		ft_sa(a, info);
	return (1);
}

int	under3(t_stack *a, t_info *info)
{
	int	x;
	int	y;
	int	z;

	x = a->head->value;
	y = a->head->next->value;
	z = a->head->next->next->value;
	if ((y > x && y > z) && z > x)
	{
		ft_rra(a, info);
		ft_sa(a, info);
	}
	else if (x > y && y > z)
	{
		ft_ra(a, info);
		ft_sa(a, info);
	}
	else if ((z > x && z > y) && x > y)
		ft_sa(a, info);
	else if ((y > x && y > z) && x > z)
		ft_rra(a, info);
	else if ((x > y && x > z) && z > y)
		ft_ra(a, info);
	return (1);
}

int	one_pivot(t_stack *a, int range, int *pivot)
{
	int		i;
	int		*num;
	t_node	*temp;

	num = (int *)malloc(range * sizeof(int));
	if (num == NULL)
		return (0);
	temp = a->head;
	if (temp == NULL)
		return (0);
	i = 0;
	while (i < range)
	{
		num[i] = temp->value;
		temp = temp->next;
		i++;
	}
	quicksort(num, 0, range - 1);
	*pivot = num[(range - 1) / 2];
	free(num);
	return (1);
}

int	under45(t_stack *a, t_stack *b, t_info *info, int range)
{
	int	pivot;
	int	i;
	int	ret;

	ret = one_pivot(a, range, &pivot);
	if (ret == 0)
		return (0);
	i = 0;
	while (i < range)
	{
		if (a->head->value < pivot)
			ft_pb(a, b, info);
		else
			ft_ra(a, info);
		++i;
	}
	under3(a, info);
	btoa(a, b, range - 3);
	return (1);
}
