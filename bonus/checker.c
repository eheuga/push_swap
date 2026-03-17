#include "checker.h"

int main(int ac, char **av)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     i;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    if (ac == 1)
        return (0);
    if (ac == 2)
    {
        av = ft_split_args(av[1]);
        ac = 1;
        while (av[ac])
            ac++;
    }
    while (i < ac)
    {
        if (!is_valid_number(av[i]))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        i++;
    }
    is_number_dup(ac, av);
    i = 1;
    while (i < ac)
    {
        add_back(&stack_a, new_node(ft_atoi(av[i])));
        i++;
    }
    do_op(&stack_a, &stack_b);
    if (sorted_verif(stack_a) && !stack_b)
    {
        free_stack(stack_a);
        write(1, "OK\n", 3);
        return (0);
    }
    free_stack(stack_a);
    write(1, "KO\n", 3);
    return (0);
}