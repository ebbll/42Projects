/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <eunji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:46:49 by eunlee            #+#    #+#             */
/*   Updated: 2021/10/27 16:18:05 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_all(t_stack *a, t_stack *b, t_info *info)
{
	init_stack(a);
	init_stack(b);
	init_info(info);
}

void	init_stack(t_stack *a)
{
	a->head = 0;
	a->tail = 0;
	a->temp = 0;
}

void	init_info(t_info *info)
{
	info->both = 0;
	info->len_a = 0;
	info->len_b = 0;
	info->pa = 0;
	info->pb = 0;
	info->ra = 0;
	info->rb = 0;
}

int	parsing(t_stack *a, t_info *info, int argc, char **argv)
{
	int	i;
	int	ret;

	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			return (0);
		while (*argv[i] != '\0')
		{
			if (*argv[i] == ' ')
				argv[i]++;
			else
			{
				ret = check_input(a, &argv[i], info);
				if (ret == 0)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_stack	stack_a;
	t_stack	stack_b;
	t_info	info;

	if (argc <= 1)
		return (0);
	init_all(&stack_a, &stack_b, &info);
	ret = parsing(&stack_a, &info, argc, argv);
	if (ret == 0)
		exit_err(&stack_a, &stack_b);
	ret = check_order(&stack_a);
	if (ret == 0)
	{
		ret = start_sort(&stack_a, &stack_b, &info);
		if (ret == 0)
			exit_err(&stack_a, &stack_b);
	}
	lstclear(&stack_a.head, &stack_a.tail);
	lstclear(&stack_b.head, &stack_b.tail);
	return (0);
}
