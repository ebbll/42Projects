/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:54:33 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/27 17:34:23 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_info *info)
{
	if (a->head == NULL || a->head->next == NULL)
		return ;
	a->tail->next = a->head;
	a->head->prev = a->tail;
	a->tail = a->head;
	a->head = a->head->next;
	if (a->head != NULL)
		a->head->prev = NULL;
	a->tail->next = NULL;
	if (info->both == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, t_info *info)
{
	if (b->head == NULL || b->head->next == NULL)
		return ;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->tail = b->head;
	b->head = b->head->next;
	if (b->head != NULL)
		b->head->prev = NULL;
	b->tail->next = NULL;
	if (info->both == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, t_info *info)
{
	info->both = 1;
	ft_ra(a, info);
	ft_rb(b, info);
	info->both = 0;
	write(1, "rr\n", 3);
}
