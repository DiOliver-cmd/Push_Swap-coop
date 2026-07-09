/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:00:00 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_best(t_cost *best)
{
	t_list	*node;
	int		size_a;
	int		idx;

	best->total = -1;
	size_a = ft_lstsize(*get_stack_a());
	node = *get_stack_a();
	idx = 0;
	while (node)
	{
		eval_node(best, idx, node->value, size_a);
		node = node->next;
		idx++;
	}
}

static void	push_best(void)
{
	t_cost	best;

	find_best(&best);
	do_moves(best.cost_a, best.dir_a, best.cost_b, best.dir_b);
	pb();
}

static void	find_best_return(t_cost *best)
{
	t_list	*node;
	int		size_b;
	int		idx;

	best->total = -1;
	size_b = ft_lstsize(*get_stack_b());
	node = *get_stack_b();
	idx = 0;
	while (node)
	{
		eval_node_b(best, idx, node->value, size_b);
		node = node->next;
		idx++;
	}
}

static void	pull_best(void)
{
	t_cost	best;

	find_best_return(&best);
	do_moves(best.cost_a, best.dir_a, best.cost_b, best.dir_b);
	pa();
}

void	sort_complex(void)
{
	while (ft_lstsize(*get_stack_a()) > 3)
		push_best();
	sort_small();
	while (*get_stack_b() != NULL)
		pull_best();
	final_rotation();
}
