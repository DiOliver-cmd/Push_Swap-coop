/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/07/08 12:30:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	update_best_min(t_list *stack, int val, int *bp, int *mp, int *i)
{
	int	bv;
	int	mv;

	bv = 2147483647;
	mv = 2147483647;
	while (stack)
	{
		if (stack->value < mv)
		{
			mv = stack->value;
			*mp = *i;
		}
		if (stack->value > val && stack->value < bv)
		{
			bv = stack->value;
			*bp = *i;
		}
		stack = stack->next;
		(*i)++;
	}
}

int	find_target_generic(t_list *stack, int value, int fallback)
{
	int	best_pos;
	int	min_pos;
	int	i;

	best_pos = -1;
	min_pos = -1;
	i = 0;
	update_best_min(stack, value, &best_pos, &min_pos, &i);
	if (best_pos != -1)
		return (best_pos);
	if (min_pos != -1)
		return (min_pos);
	return (fallback);
}

static void	rotate_n(int n, int dir, int which)
{
	while (n-- > 0)
	{
		if (which == 0)
		{
			if (dir)
				ra();
			else
				rra();
		}
		else if (which == 1)
		{
			if (dir)
				rb();
			else
				rrb();
		}
		else
		{
			if (dir)
				rr();
			else
				rrr();
		}
	}
}

void	do_moves(int cost_a, int dir_a, int cost_b, int dir_b)
{
	int	both;

	both = 0;
	if (dir_a == dir_b)
	{
		if (cost_a < cost_b)
			both = cost_a;
		else
			both = cost_b;
	}
	rotate_n(both, dir_a, 2);
	rotate_n(cost_a - both, dir_a, 0);
	rotate_n(cost_b - both, dir_b, 1);
}
