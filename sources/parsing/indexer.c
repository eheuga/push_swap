/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:38:30 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*indexer(t_node **stack_a)
{
	int		size;
	int		i;
	int		*tab;
	t_node	*current;

	size = get_size(*stack_a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	current = *stack_a;
	i = 0;
	while (current != NULL)
	{
		tab[i] = current->value;
		i++;
		current = current->next;
	}
	bubble_sort(tab, size);
	return (tab);
}

void	set_index(t_node **stack_a, int *index_tab)
{
	t_node	*current;
	int		i;

	current = *stack_a;
	while (current != NULL)
	{
		i = 0;
		while (current->value != index_tab[i])
		{
			i++;
		}
		current->value = i;
		current = current->next;
	}
}
