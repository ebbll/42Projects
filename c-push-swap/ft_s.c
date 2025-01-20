/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:07:29 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/27 17:33:01 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_info *info)
{
	t_node	*temp;
	t_node	*next_temp;

	temp = a->head;
	if (a->head == NULL || a->head->next == NULL)
		return ;
	next_temp = temp->next->next;
	a->head = a->head->next;
	a->head->prev = NULL;
	a->head->next = temp;
	a->head->next->prev = a->head;
	a->head->next->next = next_temp;
	if (next_temp != NULL)
		a->head->next->next->prev = a->head->next;
	if (next_temp == NULL)
		a->tail = temp;
	if (info->both == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, t_info *info)
{
	t_node	*temp;
	t_node	*next_temp;

	temp = b->head;
	if (b->head == NULL || b->head->next == NULL)
		return ;
	next_temp = temp->next->next;
	b->head = b->head->next;
	b->head->prev = NULL;
	b->head->next = temp;
	b->head->next->prev = b->head;
	b->head->next->next = next_temp;
	if (next_temp != NULL)
		b->head->next->next->prev = b->head->next;
	if (next_temp == NULL)
		b->tail = temp;
	if (info->both == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b, t_info *info)
{
	info->both = 1;
	ft_sa(a, info);
	ft_sb(b, info);
	info->both = 0;
	write(1, "ss\n", 3);
}
