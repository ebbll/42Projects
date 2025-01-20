/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunji <eunji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:48:38 by eunlee            #+#    #+#             */
/*   Updated: 2021/10/28 12:20:53 by eunji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	t_node	*temp;
}				t_stack;

typedef struct s_info
{
	int		check;
	int		both;
	int		len_a;
	int		len_b;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
}				t_info;

/* ft_p.c */
void		ft_pa(t_stack *a, t_stack *b, t_info *info);
void		ft_pb(t_stack *a, t_stack *b, t_info *info);

/* ft_s.c */
void		ft_sa(t_stack *a, t_info *info);
void		ft_sb(t_stack *b, t_info *info);
void		ft_ss(t_stack *a, t_stack *b, t_info *info);

/* ft_r.c */
void		ft_ra(t_stack *a, t_info *info);
void		ft_rb(t_stack *b, t_info *info);
void		ft_rr(t_stack *a, t_stack *b, t_info *info);

/* ft_rr.c */
void		ft_rra(t_stack *a, t_info *info);
void		ft_rrb(t_stack *b, t_info *info);
void		ft_rrr(t_stack *a, t_stack *b, t_info *info);

/* util.c */
int			ft_wordlen(char *str);
long long	atolong(char *str);
int			check_dup(t_stack *a, int value);
int			check_order(t_stack *a);
int			check_reorder(t_stack *a, t_stack *b, t_info *info, int range);

/* check_input.c */
int			check_valid(char *argv);
int			check_range(char *argv, int *ret);
int			check_input(t_stack *a, char **argv, t_info *info);

/* list.c */
t_node		*lstnew(int value);
void		lstadd_back(t_stack *a, int value);
void		lstclear(t_node **head, t_node **tail);

/* quicksort.c */
void		swap(int *a, int *b);
int			partition(int *num, int left, int right);
void		quicksort(int *num, int left, int right);

/* start_sort.c */
int			pick_pivot(t_stack *a, int range, int pivot[2]);
void		divide(t_stack *a, t_stack *b, t_info *info, int *pivot);
int			start_sort(t_stack *a, t_stack *b, t_info *info);

/* divide.c */
t_info		divide_a(t_stack *a, t_stack *b, int pivot[2], int range);
t_info		divide_b(t_stack *a, t_stack *b, int pivot[2], int range);

/* sort.c */
void		rewind_ab(t_stack *a, t_stack *b, t_info *info);
int			pre_sort_b(t_stack *a, t_stack *b, t_info *info, int range);
int			atob(t_stack *a, t_stack *b, int range);
int			btoa(t_stack *a, t_stack *b, int range);

/* exit_a.c */
int			under2(t_stack *a, t_info *info);
int			under3(t_stack *a, t_info *info);
int			under45(t_stack *a, t_stack *b, t_info *info, int range);

/* push_swap.c */
void		init_all(t_stack *a, t_stack *b, t_info *info);
void		init_stack(t_stack *a);
void		init_info(t_info *info);
int			parsing(t_stack *a, t_info *info, int argc, char **argv);

/* err.c */
void		exit_err(t_stack *a, t_stack *b);

#endif
