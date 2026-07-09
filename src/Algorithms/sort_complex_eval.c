/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_eval.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:00:00 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/08 12:45:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	try_same_dir(t_cost *best, int idx, t_node_costs *c, int dir)
{
	int	cost_a;
	int	cost_b;
	int	total;

	cost_a = c->ca_down;
	if (dir)
		cost_a = c->ca_up;
	cost_b = c->cb_down;
	if (dir)
		cost_b = c->cb_up;
	total = cost_b;
	if (cost_a > cost_b)
		total = cost_a;
	if (best->total == -1 || total < best->total)
	{
		best->total = total;
		best->idx_a = idx;
		best->cost_a = cost_a;
		best->dir_a = dir;
		best->cost_b = cost_b;
		best->dir_b = dir;
	}
}

void	try_mixed_dir(t_cost *best, int idx, t_node_costs *c, int dir_a)
{
	int	cost_a;
	int	cost_b;
	int	total;

	cost_a = c->ca_down;
	if (dir_a)
		cost_a = c->ca_up;
	cost_b = c->cb_up;
	if (dir_a)
		cost_b = c->cb_down;
	total = cost_a + cost_b;
	if (total < best->total)
	{
		best->total = total;
		best->idx_a = idx;
		best->cost_a = cost_a;
		best->dir_a = dir_a;
		best->cost_b = cost_b;
		best->dir_b = !dir_a;
	}
}

void	eval_node(t_cost *best, int idx, int value, int size_a)
{
	t_node_costs	c;
	int				size_b;
	int				target_idx;

	size_b = ft_lstsize(*get_stack_b());
	target_idx = find_target_generic(*get_stack_b(), value, size_b);
	c.ca_up = idx;
	c.ca_down = size_a - idx;
	c.cb_up = target_idx;
	c.cb_down = size_b - target_idx;
	try_same_dir(best, idx, &c, 1);
	try_same_dir(best, idx, &c, 0);
	try_mixed_dir(best, idx, &c, 1);
	try_mixed_dir(best, idx, &c, 0);
}

void	eval_node_b(t_cost *best, int idx, int value, int size_b)
{
	t_node_costs	c;
	int				size_a;

	size_a = ft_lstsize(*get_stack_a());
	c.cb_up = idx;
	c.cb_down = size_b - idx;
	c.ca_up = find_target_generic(*get_stack_a(), value, 0);
	c.ca_down = size_a - c.ca_up;
	try_same_dir(best, idx, &c, 1);
	try_same_dir(best, idx, &c, 0);
	try_mixed_dir(best, idx, &c, 1);
	try_mixed_dir(best, idx, &c, 0);
}
