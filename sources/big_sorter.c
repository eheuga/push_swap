#include "pushswap.h"



int get_stack_size (t_node *stack){
    int size = 0;

    while (stack != NULL){
        size++;
        stack = stack->next;
    }
    return size;
}

void push_chunks(t_node **stack_a, t_node **stack_b)
{
    int size = get_stack_size(*stack_a);
    int delta = size / 20 + 7;
    int threshold = 0;

    while (*stack_a)
    {
        if ((*stack_a)->value <= delta + threshold)
        {
            push_b(stack_a, stack_b);
            if ((*stack_b)->value <= threshold)
                rotate_b(stack_b, 1);
            threshold++;
        }
        else
            rotate_a(stack_a, 1);
    }
}



int find_max (t_node *stack_b){
    
    t_node *current = stack_b;
    int max = stack_b->value;
    
    while (current != NULL){
        if (current->value > max)
        max = current->value;
    current = current->next;
    
}
return max;
}

int find_position(t_node *stack, int value)
{
    t_node  *current = stack;
    int     pos = 0;

    while (current->value != value)
    {
        pos++;
        current = current->next;
    }
    return pos;
}

void push_max (t_node **stack_a, t_node **stack_b, int max){
    
    int pos;
    int stack_size = 0;
    t_node *current = *stack_b;

    while (current != NULL){
        stack_size++;
        current = current->next;
    }
    
    pos = find_position(*stack_b, max);

    if (pos < stack_size/2){
    
        while ((*stack_b)->value != max)
            rotate_b(stack_b, 1);

        push_a (stack_a, stack_b);
    }

    else {

        while ((*stack_b)->value != max)
            reverse_rotate_b(stack_b, 1);

        push_a (stack_a, stack_b);
    }

}