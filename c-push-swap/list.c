/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:10:43 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/22 12:19:47 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew(int value)
{
	t_node	*new_ele;

	new_ele = (t_node *)malloc(sizeof(t_node));
	if (!new_ele)
		return (NULL);
	new_ele->value = value;
	new_ele->next = NULL;
	new_ele->prev = NULL;
	return (new_ele);
}

void	lstadd_back(t_stack *a, int value)
{
	t_node	*node;

	a->temp = lstnew(value);
	if (a->temp == NULL)
		return ;
	if (a->head == NULL)
	{
		a->head = a->temp;
		a->tail = a->temp;
		return ;
	}
	node = a->head;
	while (node->next)
		node = node->next;
	a->temp->next = node->next;
	node->next = a->temp;
	a->temp->prev = node;
	a->tail = a->temp;
}

void	lstclear(t_node **head, t_node **tail)
{
	t_node	*temp;

	if (head == NULL || *head == NULL)
		return ;
	temp = (*head);
	while ((*head) != NULL)
	{
		temp = (*head)->next;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->value = 0;
		free(*head);
		(*head) = NULL;
		(*head) = temp;
	}
	head = NULL;
	tail = NULL;
}
