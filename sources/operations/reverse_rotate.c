/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
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

void	reverse_rotate_a(t_node **stack_a, int print)
{
	t_node	*tmp;
	t_node	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	tmp = tmp->next;
	before_last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_node **stack_b, int print)
{
	t_node	*tmp;
	t_node	*before_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	tmp = tmp->next;
	before_last->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
