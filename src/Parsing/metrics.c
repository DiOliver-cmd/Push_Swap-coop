/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:25:14 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	select_strategy(t_options *opt)
{
	if (opt->strategy == STRAT_SIMPLE)
		opt->used = STRAT_SIMPLE;
	else if (opt->strategy == STRAT_MEDIUM)
		opt->used = STRAT_MEDIUM;
	else if (opt->strategy == STRAT_COMPLEX)
		opt->used = STRAT_COMPLEX;
	else if (opt->disorder < 0.2)
		opt->used = STRAT_SIMPLE;
	else if (opt->disorder < 0.5)
		opt->used = STRAT_MEDIUM;
	else
		opt->used = STRAT_COMPLEX;
}

void	dispatch_algorithm(t_options *opt)
{
	opt->disorder = calc_desorder();
	if (opt->disorder == 0.0)
		my_exit(1);
	select_strategy(opt);
	if (opt->used == STRAT_SIMPLE)
		sort_simple();
	else if (opt->used == STRAT_MEDIUM)
		sort_medium();
	else
		sort_complex();
	if (opt->bench_mode)
		show_bench(opt);
}
