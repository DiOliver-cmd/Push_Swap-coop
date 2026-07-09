/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:43:00 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_rest(void)
{
	t_data	*d;

	d = get_data();
	ft_putnbr_fd(d->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(d->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(d->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(d->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(d->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(d->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(d->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(d->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(d->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(d->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	show_bench(t_options *opt)
{
	t_data	*d;

	d = get_data();
	ft_putstr_fd("[bench] disorder: ", 2);
	put_float(opt->disorder * 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(opt->strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity_name(opt->used), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(d), 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(d->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	print_rest();
}
