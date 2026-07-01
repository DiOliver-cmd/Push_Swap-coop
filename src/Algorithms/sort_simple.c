/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:36:27 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/01 16:36:56 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index(t_list *stack)
{
	int		i;
	int		min_i;
	long	min_val;

	i = 0;
	min_i = 0;
	min_val = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_i = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_i);
}

static void	move_min_to_top(int idx, int size)
{
	if (idx <= size - idx)
	{
		while (idx-- > 0)
			ra();
	}
	else
	{
		idx = size - idx;
		while (idx-- > 0)
			rra();
	}
}

void	sort_simple(void)
{
	int	size;
	int	idx;

	size = ft_lstsize(*(get_stack_a()));
	while (size > 1)
	{
		idx = find_min_index(*(get_stack_a()));
		move_min_to_top(idx, size);
		pb();
		size--;
	}
	while (*(get_stack_b()) != NULL)
		pa();
}
