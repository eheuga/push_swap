/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:19:06 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	is_number_dup(ac, av);
}

static void	sort(t_node **stack_a, t_node **stack_b, int args_nbr)
{
	int	max;

	if (args_nbr == 2)
		swap_a(stack_a, 1);
	else if (args_nbr == 3)
		little_sorter(stack_a);
	else if (args_nbr == 4)
		little_sorter4(stack_a, stack_b);
	else if (args_nbr == 5)
		little_sorter5(stack_a, stack_b);
	else
	{
		k_sort(stack_a, stack_b);
		while (*stack_b)
		{
			max = find_max(*stack_b);
			push_max(stack_a, stack_b, max);
		}
	}
}

int	main(int ac, char **av)
{
	int		*index_tab;
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
		if (!av[1] || av[1][0] == '\0')
			return (write(2, "Error\n", 6), 1);
		av = ft_split(av[1]);
		if (!av || !av[1])
			return (0);
		ac = 1;
		while (av[ac])
			ac++;
	}
	validate_args(ac, av);
	while (i < ac)
		add_back(&stack_a, new_node(ft_atoi(av[i++])));
	if (sorted_verif(stack_a))
		return (free_stack(stack_a), 0);
	index_tab = indexer(&stack_a);
	set_index(&stack_a, index_tab);
	sort(&stack_a, &stack_b, ac - 1);
	free_stack(stack_a);
	free_stack(stack_b);
	free(index_tab);
	return (0);
}
