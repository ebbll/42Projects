/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:11:35 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/27 17:33:44 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, t_info *info)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	a->head->prev = a->tail;
	a->tail->next = a->head;
	a->head = a->tail;
	a->tail = a->tail->prev;
	a->head->prev = NULL;
	if (a->tail != NULL)
		a->tail->next = NULL;
	if (info->both == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, t_info *info)
{
	if (b->head == NULL || b->head->next == NULL)
		return ;
	b->head->prev = b->tail;
	b->tail->next = b->head;
	b->head = b->tail;
	b->tail = b->tail->prev;
	b->head->prev = NULL;
	if (b->tail != NULL)
		b->tail->next = NULL;
	if (info->both == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, t_info *info)
{
	info->both = 1;
	ft_rra(a, info);
	ft_rrb(b, info);
	info->both = 0;
	write(1, "rrr\n", 4);
}
