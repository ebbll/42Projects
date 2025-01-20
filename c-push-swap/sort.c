/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:01:15 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/29 15:52:14 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_sort_b(t_stack *a, t_stack *b, t_info *info, int range)
{
	int	ret;

	ret = 0;
	init_info(info);
	if (range < 2)
	{
		if (range == 1)
			ft_pa(a, b, info);
		return (1);
	}
	return (0);
}

void	rewind_ab(t_stack *a, t_stack *b, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->ra && i < info->rb)
	{
		ft_rrr(a, b, info);
		i++;
	}
	while (i < info->ra)
	{
		ft_rra(a, info);
		i++;
	}
	while (i < info->rb)
	{
		ft_rrb(b, info);
		i++;
	}
}

int	atob(t_stack *a, t_stack *b, int range)
{
	int		ret;
	int		pivot[2];
	t_info	info;

	if (range < 2)
		return (1);
	init_info(&info);
	ret = pick_pivot(a, range, pivot);
	if (ret == 0)
		return (0);
	info = divide_a(a, b, pivot, range);
	rewind_ab(a, b, &info);
	atob(a, b, info.ra);
	btoa(a, b, info.rb);
	btoa(a, b, info.pb - info.rb);
	return (1);
}

int	btoa(t_stack *a, t_stack *b, int range)
{
	int		ret;
	int		pivot[2];
	t_info	info;

	if (range < 1)
		return (1);
	ret = pre_sort_b(a, b, &info, range);
	if (ret)
		return (1);
	ret = pick_pivot(b, range, pivot);
	if (ret == 0)
		return (0);
	info = divide_b(a, b, pivot, range);
	atob(a, b, info.pa - info.ra);
	rewind_ab(a, b, &info);
	atob(a, b, info.ra);
	btoa(a, b, info.rb);
	return (1);
}
