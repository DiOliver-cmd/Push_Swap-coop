/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:34:37 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/23 13:20:30 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || *stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	if (first->next)
	first->next->prev = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}
