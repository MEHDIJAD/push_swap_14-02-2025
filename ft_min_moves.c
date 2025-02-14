/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:55:09 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/07 15:19:27 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_min_move(t_list **stack, int index)
{
	t_move *moves;
	int	size = ft_lstsize(*stack);	
	int mid = size / 2;

	moves = malloc(sizeof(t_move)); //!
	moves->mv = 0;
	moves->op = NULL;
	if (index < mid)
	{
		moves->mv = index;
		moves->op = "ra";
	}
	else if (index >= mid)
	{
		moves->mv = size - index;
		moves->op = "rra";
	}
	return (moves);
}
