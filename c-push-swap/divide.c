/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:50:53 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/29 15:52:02 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	divide_a(t_stack *a, t_stack *b, int pivot[2], int range)
{
	t_info	info;

	init_info(&info);
	if (range < 2)
		return (info);
	while (range-- > 0)
	{
		if (a->head->value >= pivot[1])
		{
			ft_ra(a, &info);
			info.ra += 1;
		}
		else
		{
			ft_pb(a, b, &info);
			info.pb += 1;
			if (b->head->value >= pivot[0])
			{
				ft_rb(b, &info);
				info.rb += 1;
			}
		}
	}
	return (info);
}

t_info	divide_b(t_stack *a, t_stack *b, int pivot[2], int range)
{
	int		i;
	t_info	info;

	i = 0;
	init_info(&info);
	while (i < range)
	{
		if (b->head->value < pivot[0])
		{
			ft_rb(b, &info);
			info.rb += 1;
		}
		else
		{
			ft_pa(a, b, &info);
			info.pa += 1;
			if (a->head->value < pivot[1])
			{
				ft_ra(a, &info);
				info.ra += 1;
			}
		}
		i++;
	}
	return (info);
}
