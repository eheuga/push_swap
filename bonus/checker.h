/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:38:30 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// stacks
t_node	*new_node(int value);
void	add_back(t_node **head, t_node *new);
void	add_front(t_node **head, t_node *new);
void	free_stack(t_node *stack);

// validation
int		is_valid_number(char *str);
int		is_number_dup(int ac, char **str);
int		sorted_verif(t_node *stack_a);

// operations
void	push_a(t_node **stack_a, t_node **stack_b, int print);
void	push_b(t_node **stack_a, t_node **stack_b, int print);
void	swap_a(t_node **stack_a, int print);
void	swap_b(t_node **b, int print);
void	sswap(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a, int print);
void	rotate_b(t_node **b, int print);
void	rotate_ab(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a, int print);
void	reverse_rotate_b(t_node **b, int print);
void	reverse_rotate_ab(t_node **stack_a, t_node **stack_b);

// utils
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *str);
int		ft_atoi(const char *nptr);

// checker
void	do_op(t_node **stack_a, t_node **stack_b);
void	op(char *op, t_node **stack_a, t_node **stack_b);
void	op_rotate(char *op, t_node **stack_a, t_node **stack_b);
int		checker(t_node **stack_a, t_node **stack_b, int ac, char **av);

#endif
