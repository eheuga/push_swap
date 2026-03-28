/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:19:06 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	op_verif(t_node **stack_a, t_node **stack_b)
{
	do_op(stack_a, stack_b);
	if (sorted_verif(*stack_a) && !(*stack_b))
	{
		free_stack(*stack_a);
		write(1, "OK\n", 3);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1]);
		ac = 1;
		while (av[ac])
			ac++;
	}
	if (!checker(&stack_a, &stack_b, ac, av))
	{
		free_stack(stack_a);
		write(1, "KO\n", 3);
	}
	return (0);
}

int	checker(t_node **stack_a, t_node **stack_b, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	is_number_dup(ac, av);
	i = 1;
	while (i < ac)
	{
		add_back(stack_a, new_node(ft_atoi(av[i])));
		i++;
	}
	if (op_verif(stack_a, stack_b))
		return (1);
	else
		return (0);
}
