/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:38:15 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/12 13:06:57 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rrotate(t_list **stack, char *op)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	second_last = *stack;
	while (second_last->next && second_last->next->next) //* the first condition check if next is NULL and the second check if next->next -s null to stop befor last
		second_last = second_last->next; //* stap at node befor second last and do next-> to get to second last
	last = second_last->next; //* asign last
	second_last->next = NULL; //* detach last by seting second last->next to NULL
	last->next = *stack; //* add to front
	*stack = last;	//* make it the new head
	if (op)
		ft_printf(1, "%s\n", op);
}