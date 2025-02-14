/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:59:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/11 12:11:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//* for 3 number 

void	ft_sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;
	
	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	c = (*stack_a)->next->next->number;
	if (a > b && b < c && a < c) //* case: 2 1 3 --> sa
		ft_op_swap(stack_a, "sa");
	else if (a > b && b > c) //* case: 3 2 1 --> sa + rra
	{
		ft_op_swap(stack_a, "sa");
		ft_op_rrotate(stack_a, "rra");
	}
	else if (a > b && b < c && a > c) //* case: 3 1 2 --> ra
		ft_op_rotate(stack_a, "ra");
	else if (a < b && b > c && a < c) //* case: 1 3 2 --> sa + ra
	{
		ft_op_swap(stack_a, "sa");
		ft_op_rotate(stack_a, "ra");
	}
	else if (a < b && b > c && a > c) //* case: 2 3 1 --> rra
		ft_op_rrotate(stack_a, "rra");		
}


