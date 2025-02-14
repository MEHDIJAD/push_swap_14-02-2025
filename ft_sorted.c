/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:26:19 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/11 14:27:51 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list *stack_a)
{
	t_list	*curr;

	if (!stack_a)
		return (0);
	curr = stack_a;
	while(curr->next) //* to stop at the second last node 
	{
		if (curr->number > curr->next->number)
			return (0);
		curr = curr->next;
	}
	return (1);
}