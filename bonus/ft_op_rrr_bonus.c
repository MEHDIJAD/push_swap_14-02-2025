/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:09:09 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/12 12:56:06 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rrr(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_op_rrotate(stack_a, NULL);
	ft_op_rrotate(stack_b, NULL);
	if (op)
		ft_printf(1, "%s\n", op);
}