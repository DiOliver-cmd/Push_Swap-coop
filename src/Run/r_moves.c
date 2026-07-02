/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:04:24 by marvin            #+#    #+#             */
/*   Updated: 2026/07/01 23:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(void)
{
    t_list  **stack;
    t_list  *first;
    t_list  *last;
    t_data  *data;

    stack = get_stack_a();

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    last = ft_lstlast(*stack);
    *stack = first->next;
    first->next = NULL;
    last->next = first;
    data = get_data();
    data->ra++;
    if (data->bench == ERR)
        write(1, "ra\n", 3);
}

void	rb(void)
{
    t_list  **stack;
    t_list  *first;
    t_list  *last;
    t_data  *data;

    stack = get_stack_b();

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    last = ft_lstlast(*stack);
    *stack = first->next;
    first->next = NULL;
    last->next = first;
    data = get_data();
    data->rb++;
    if (data->bench == ERR)
        write(1, "rb\n", 3);
}

void	rr(void)
{
	ra();
	rb();
}