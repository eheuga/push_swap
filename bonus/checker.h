#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// utils
t_node  *new_node(int value);
void    add_back(t_node **head, t_node *new);
void    add_front(t_node **head, t_node *new);
char    **ft_split_args(char *str);

// validation
int     is_valid_number(char *str);
int     is_number_dup(int ac, char **str);
int     ft_atoi(char *str);
int     sorted_verif(t_node *stack_a);

// operations
void    push_a(t_node **stack_a, t_node **stack_b);
void    push_b(t_node **stack_a, t_node **stack_b);
void    swap_a(t_node **stack_a, int print);
void    swap_b(t_node **b, int print);
void    sswap(t_node **stack_a, t_node **stack_b);
void    rotate_a(t_node **stack_a, int print);
void    rotate_b(t_node **b, int print);
void    rotate_ab(t_node **stack_a, t_node **stack_b);
void    reverse_rotate_a(t_node **stack_a, int print);
void    reverse_rotate_b(t_node **b, int print);
void    reverse_rotate_ab(t_node **stack_a, t_node **stack_b);

// free
void    free_stack(t_node *stack);

// checker
void    do_op(t_node **stack_a, t_node **stack_b);

#endif