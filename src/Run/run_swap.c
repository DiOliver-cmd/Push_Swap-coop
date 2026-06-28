/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:34:37 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/28 14:16:12 by dilferre         ###   ########.fr       */
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

void	sb(t_stacks *stacks)
{
	t_node	*first;
	t_node	*second;
	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	first = stacks->b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	stacks->b = second;
	write(1, "sb\n", 3);
}

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	write(1, "ss\n", 3);
}
