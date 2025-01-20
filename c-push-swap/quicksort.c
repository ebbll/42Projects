/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:40:22 by eunlee            #+#    #+#             */
/*   Updated: 2021/09/29 12:57:25 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *num, int left, int right)
{
	int	first;
	int	pivot;

	first = left;
	pivot = num[first];
	left++;
	while (left <= right)
	{
		while (num[left] <= pivot && left < right)
			left++;
		while (num[right] >= pivot && left <= right)
			right--;
		if (left < right)
			swap(&num[left], &num[right]);
		else
			break ;
	}
	swap(&num[first], &num[right]);
	return (right);
}

void	quicksort(int *num, int left, int right)
{
	int	index;

	if (left < right)
	{
		index = partition(num, left, right);
		quicksort(num, left, index - 1);
		quicksort(num, index + 1, right);
	}
}
