/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:29:43 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/27 17:34:46 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_pa(t_stack *a, t_stack *b, t_info *info)
{
	t_node	*temp;

	if (b->head == NULL)
		return ;
	info->len_a += 1;
	info->len_b -= 1;
	temp = a->head;
	a->head = b->head;
	b->head = b->head->next;
	if (b->head != NULL)
		b->head->prev = NULL;
	if (!temp)
	{
		a->head->next = NULL;
		a->head->prev = NULL;
		a->tail = a->head;
	}
	else
	{
		a->head->next = temp;
		temp->prev = a->head;
	}
	if (b->head == NULL)
		b->tail = NULL;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b, t_info *info)
{
	t_node	*temp;

	if (a->head == NULL)
		return ;
	info->len_a -= 1;
	info->len_b += 1;
	temp = b->head;
	b->head = a->head;
	a->head = a->head->next;
	if (a->head != NULL)
		a->head->prev = NULL;
	if (!temp)
	{
		b->head->next = NULL;
		b->head->prev = NULL;
		b->tail = b->head;
	}
	else
	{
		b->head->next = temp;
		temp->prev = b->head;
	}
	if (a->head == NULL)
		a->tail = NULL;
	write(1, "pb\n", 3);
}
