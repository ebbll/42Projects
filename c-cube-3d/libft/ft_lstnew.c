/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:04:33 by eunlee            #+#    #+#             */
/*   Updated: 2020/07/30 11:54:50 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_ele;

	new_ele = (t_list *)malloc(sizeof(t_list));
	if (!new_ele)
		return (NULL);
	new_ele->content = content;
	new_ele->next = NULL;
	return (new_ele);
}
