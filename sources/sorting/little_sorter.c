/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/24 16:05:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	little_sorter(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && c > a)
		swap_a(stack_a, 1);
	else if (a > c && c > b)
		rotate_a(stack_a, 1);
	else if (b > a && b > c && c > a)
	{
		reverse_rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	else if (b > a && a > c && b > c)
		reverse_rotate_a(stack_a, 1);
	else if (a > b && a > c)
	{
		rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
}

int	find_min(t_node *stack_a)
{
	int		min;
	t_node	*current;

	min = stack_a->value;
	current = stack_a;
	while (current->next != NULL)
	{
		if (min > current->next->value)
			min = current->next->value;
		current = current->next;
	}
	return (min);
}

void	push_min(t_node **stack_a, t_node **stack_b, int min)
{
	while ((*stack_a)->value != min)
		rotate_a(stack_a, 1);
	push_b(stack_a, stack_b, 1);
}

void	little_sorter4(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = 0;
	min = find_min(*stack_a);
	push_min(stack_a, stack_b, min);
	little_sorter(stack_a);
	push_a(stack_a, stack_b, 1);
}

void	little_sorter5(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = 0;
	min = find_min(*stack_a);
	push_min(stack_a, stack_b, min);
	min = find_min(*stack_a);
	push_min(stack_a, stack_b, min);
	if ((*stack_b)->value < (*stack_b)->next->value)
		swap_b(stack_b, 1);
	little_sorter(stack_a);
	push_a(stack_a, stack_b, 1);
	push_a(stack_a, stack_b, 1);
}
