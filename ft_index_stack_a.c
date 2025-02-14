/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:12:23 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:24:12 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_next_min(t_list *lst, int idx)
{
	t_list	*curr;
	t_list	*min_node;

	curr = lst;
	min_node = NULL;
	while (curr)
	{
		if (curr->index == -1)
		{
			if (!min_node || curr->number < min_node->number)
				min_node = curr;
		}
		curr = curr->next;
	}
	if (min_node)
		min_node->index = idx;
}

void	ft_index_stack_a(t_list **lst)
{
	int		size;
	int		i;
	int		idx;

	size = ft_lstsize(*lst);
	i = 0;
	idx = 0;
	while (i < size)
	{
		ft_find_next_min(*lst, idx);
		idx++;
		i++;
	}
}
