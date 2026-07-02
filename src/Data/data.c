/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:43:00 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/01 23:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_data	*get_data(void)
{
	static t_data	data = {
		.sa = 0, .sb = 0, .ss = 0, .pa = 0, .pb = 0,
		.ra = 0, .rb = 0, .rr = 0, .rra = 0, .rrb = 0, .rrr = 0,
		.bench = ERR,
	};

	return (&data);
}

static char	*strategy_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("Simple");
	if (s == STRAT_MEDIUM)
		return ("Medium");
	if (s == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*complexity_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("O(n2)");
	if (s == STRAT_MEDIUM)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

static int	total_ops(t_data *d)
{
	return (d->sa + d->sb + d->ss + d->pa + d->pb
		+ d->ra + d->rb + d->rr + d->rra + d->rrb + d->rrr);
}

void	show_bench(t_options *opt)
{
	t_data	*d;

	d = get_data();
	fprintf(stderr, "[bench] disorder: %.2f%%\n", opt->disorder * 100);
	fprintf(stderr, "[bench] strategy: %s / %s\n",
		strategy_name(opt->strategy), complexity_name(opt->used));
	fprintf(stderr, "[bench] total_ops: %d\n", total_ops(d));
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		d->sa, d->sb, d->ss, d->pa, d->pb);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		d->ra, d->rb, d->rr, d->rra, d->rrb, d->rrr);
}
