/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:12:21 by marvin            #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(void)
{
	t_list	**stack;
	t_list	*last;
	t_list	*penultimate;

	stack = get_stack_a();
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	penultimate = *stack;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
	get_data()->rra++;
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	t_list	**stack;
	t_list	*last;
	t_list	*penultimate;

	stack = get_stack_b();
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	penultimate = *stack;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
	get_data()->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(void)
{
	rra();
	rrb();
}
