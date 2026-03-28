/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:38:30 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	op_rotate(char *op, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(op, "ra") == 0)
		rotate_a(stack_a, 0);
	else if (ft_strcmp(op, "rb") == 0)
		rotate_b(stack_b, 0);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate_a(stack_a, 0);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate_b(stack_b, 0);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_ab(stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	op(char *op, t_node **stack_a, t_node **stack_b)
{
	if (ft_strcmp(op, "pa") == 0)
		push_a(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(stack_a, stack_b, 0);
	else if (ft_strcmp(op, "sa") == 0)
		swap_a(stack_a, 0);
	else if (ft_strcmp(op, "sb") == 0)
		swap_b(stack_b, 0);
	else if (ft_strcmp(op, "ss") == 0)
		sswap(stack_a, stack_b);
	else
		op_rotate(op, stack_a, stack_b);
}

void	do_op(t_node **stack_a, t_node **stack_b)
{
	char	*tmp;
	char	buffer[1];
	char	*start;

	tmp = malloc(5);
	if (!tmp)
		return ;
	start = tmp;
	while (read(0, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
		{
			*tmp = '\0';
			op(start, stack_a, stack_b);
			tmp = start;
		}
		else
		{
			*tmp = buffer[0];
			tmp++;
		}
	}
	free(start);
}
