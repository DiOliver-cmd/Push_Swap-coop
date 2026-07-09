/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:33:58 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/01 16:34:20 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_stack(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

void	sa(void)
{
	swap_stack(get_stack_a());
	get_data()->sa++;
	write(1, "sa\n", 3);
}

void	sb(void)
{
	swap_stack(get_stack_b());
	get_data()->sb++;
	write(1, "sb\n", 3);
}

void	ss(void)
{
	swap_stack(get_stack_a());
	swap_stack(get_stack_b());
	get_data()->ss++;
	write(1, "ss\n", 3);
}
