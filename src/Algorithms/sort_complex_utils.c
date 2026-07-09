/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:00:00 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/08 12:30:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	update_best_min(t_list *stack, t_best_func_args args)
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
			*(args.mp) = *(args.i);
		}
		if (stack->value > args.val && stack->value < bv)
		{
			bv = stack->value;
			*(args.bp) = *(args.i);
		}
		stack = stack->next;
		(*args.i)++;
	}
}

int	find_target_generic(t_list *stack, int value, int fallback)
{
	int					best_pos;
	int					min_pos;
	int					i;
	t_best_func_args	args;

	best_pos = -1;
	min_pos = -1;
	i = 0;
	args.val = value;
	args.bp = &best_pos;
	args.mp = &min_pos;
	args.i = &i;
	update_best_min(stack, args);
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
