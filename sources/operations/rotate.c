/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:05:03 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/24 16:05:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>
#include <stdlib.h>

void	rotate_a(t_node **stack_a, int print)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	if (print)
	{
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_node **stack_b, int print)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	if (print)
	{
		write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	write(1, "rr\n", 3);
}
