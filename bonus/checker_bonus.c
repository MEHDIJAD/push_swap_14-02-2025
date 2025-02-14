/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:09:25 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 13:12:56 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_correct_arg(char *arg)
{
	const char	*valid_cmds[12];
	int			i;

	valid_cmds[0] = "sa\n";
	valid_cmds[1] = "sb\n";
	valid_cmds[2] = "ss\n";
	valid_cmds[3] = "pa\n";
	valid_cmds[4] = "pb\n";
	valid_cmds[5] = "ra\n";
	valid_cmds[6] = "rb\n";
	valid_cmds[7] = "rr\n";
	valid_cmds[8] = "rra\n";
	valid_cmds[9] = "rrb\n";
	valid_cmds[10] = "rrr\n";
	valid_cmds[11] = NULL;
	i = 0;
	while (valid_cmds[i])
	{
		if (!ft_strncmp(arg, valid_cmds[i], ft_strlen(valid_cmds[i]) + 1))
			return (1);
		i++;
	}
	return (0);
}
	

char	*ft_get_argument(t_list **stack_a, t_list **stack_b)
{
	char	*input;
	char	*arg;
	char	*temp;
	
	input = NULL; //? 
	while(1)
	{
		arg = get_next_line(0);
		if (!arg)
			break;
		if (!ft_correct_arg(arg))
		{
			get_next_line(-1); //! good code 
			return (free(arg),free(input),ft_lstclear(stack_a), ft_lstclear(stack_b), ft_printf(1,"Error\n"),exit(1), NULL);
		}
		temp = ft_strjoined(input, arg);
		free(input);
		input = temp;
		if (!input)
			return(free(arg), NULL);
		free(arg); //!
	}
	if (arg)
		free(arg);
	return (input);	
}
int	ft_sort_with_arg(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		return (ft_op_swap(stack_a,NULL),3);
	else if (!ft_strncmp(input, "sb\n", 3))
		return (ft_op_swap(stack_b,NULL), 3);
	else if (!ft_strncmp(input, "ss\n", 3))
		return (ft_op_ss(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "pa\n", 3))
		return (ft_op_push(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "pb\n", 3))
		return (ft_op_push(stack_b, stack_a, NULL), 3);	
	else if (!ft_strncmp(input, "ra\n", 3))
		return (ft_op_rotate(stack_a, NULL), 3);
	else if (!ft_strncmp(input, "rb\n", 3))
		return (ft_op_rotate(stack_b, NULL), 3);
	else if (!ft_strncmp(input, "rr\n", 3))
		return (ft_op_rr(stack_a, stack_b, NULL), 3);
	else if (!ft_strncmp(input, "rra\n", 4))
		return (ft_op_rrotate(stack_a, NULL), 4);
	else if (!ft_strncmp(input, "rrb\n", 4))
		return (ft_op_rrotate(stack_b, NULL), 4);
	else if (!ft_strncmp(input, "rrr\n", 4))
		return (ft_op_rrr(stack_a, stack_b, NULL), 4);
	return (0);
}

static int	ft_result(t_list **stack_a, t_list **stack_b, char *input)
{
	if (!input)
	{
		if (ft_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
			return(ft_lstclear(stack_a),ft_printf(2,"OK\n"), 0);
		else
			return(ft_lstclear(stack_a),ft_printf(2,"KO\n"), 1);	
	}	
	else if (input)
	{
		while (*input)
		input += ft_sort_with_arg(stack_a, stack_b, input);
	}
	if (ft_sorted(*stack_a) && ft_lstsize(*stack_b) == 0)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	return (0);
}
int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*input;
	char	*original_input;
	//int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	ft_check_input(av);
	ft_fill_stack_a(av, &stack_a);
	if (!stack_a)
		return (1);
	ft_index_stack_a(&stack_a);
	input = ft_get_argument(&stack_a, &stack_b);
	//if (!input)
	//{
	//	if (ft_sorted(stack_a) && ft_lstsize(stack_b) == 0)
	//		return(ft_lstclear(&stack_a),ft_printf(2,"OK\n"), 0);
	//	else
	//		return(ft_lstclear(&stack_a),ft_printf(2,"KO\n"), 1);	
	//}
	//i = 0;
	original_input = input;
	ft_result(&stack_a, &stack_b, input);
	//while (*input)
	//	input += ft_sort_with_arg(&stack_a, &stack_b, input);
	if (original_input)
		free(original_input);
	//if (ft_sorted(stack_a) && ft_lstsize(stack_b) == 0)
	//	ft_printf(1, "OK\n");
	//else
	//	ft_printf(1, "KO\n");
	ft_lstclear(&stack_a);
}
