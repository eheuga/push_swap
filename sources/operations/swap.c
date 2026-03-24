/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
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

void	swap_a(t_node **stack_a, int print)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = *stack_a;
	tmp2 = (*stack_a)->next;
	tmp3 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	*stack_a = tmp2;
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_node **stack_b, int print)
{
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	tmp1 = *stack_b;
	tmp2 = (*stack_b)->next;
	tmp3 = tmp2->next;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	*stack_b = tmp2;
	if (print)
		write(1, "sb\n", 3);
}

void	sswap(t_node **stack_a, t_node **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}
