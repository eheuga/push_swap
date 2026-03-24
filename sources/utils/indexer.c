/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/24 16:05:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*indexer(t_node **stack_a)
{
	int		size;
	int		i;
	int		j;
	int		tmp;
	int		*tab;
	t_node	*current;

	size = 0;
	i = 0;
	j = 0;
	tmp = 0;
	current = NULL;
	current = *stack_a;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	current = *stack_a;
	while (current != NULL)
	{
		tab[i] = current->value;
		i++;
		current = current->next;
	}
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
