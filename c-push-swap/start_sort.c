/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:48:59 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/29 15:50:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_pivot(t_stack *a, int range, int pivot[2])
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
	pivot[0] = num[range / 3];
	pivot[1] = num[range * 2 / 3];
	free(num);
	return (1);
}

void	divide(t_stack *a, t_stack *b, t_info *info, int pivot[2])
{
	int	i;
	int	temp;

	i = 0;
	temp = info->len_a;
	while (i < temp)
	{
		if (a->head->value >= pivot[1])
		{
			ft_ra(a, info);
			info->ra += 1;
		}
		else
		{
			ft_pb(a, b, info);
			info->pb += 1;
			if (b->head->value >= pivot[0])
			{
				ft_rb(b, info);
				info->rb += 1;
			}
		}
		i++;
	}
}

int	start_sort(t_stack *a, t_stack *b, t_info *info)
{
	int	pivot[2];
	int	ret;

	ret = 0;
	if (info->len_a == 2)
		ret = under2(a, info);
	else if (info->len_a == 3)
		ret = under3(a, info);
	else if (info->len_a == 4 || info->len_a == 5)
		ret = under45(a, b, info, info->len_a);
	if (ret == 1)
		return (1);
	ret = pick_pivot(a, info->len_a, pivot);
	if (ret == 0)
		return (0);
	divide(a, b, info, pivot);
	rewind_ab(a, b, info);
	atob(a, b, info->ra);
	btoa(a, b, info->rb);
	btoa(a, b, info->pb - info->rb);
	return (1);
}
