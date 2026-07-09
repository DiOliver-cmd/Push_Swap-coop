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

char	*strategy_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("Simple");
	if (s == STRAT_MEDIUM)
		return ("Medium");
	if (s == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*complexity_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("O(n2)");
	if (s == STRAT_MEDIUM)
		return ("O(n*sqrt(n))");
	if (s == STRAT_COMPLEX)
		return ("O(n log n)");
	return ("O(n log n)");
}

int	total_ops(t_data *d)
{
	return (d->sa + d->sb + d->ss + d->pa + d->pb
		+ d->ra + d->rb + d->rr + d->rra + d->rrb + d->rrr);
}

void	put_float(double n, int fd)
{
	int	integer_part;
	int	fractional_part;

	integer_part = (int)n;
	fractional_part = (int)((n - integer_part) * 100);
	ft_putnbr_fd(integer_part, fd);
	ft_putstr_fd(".", fd);
	if (fractional_part < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(fractional_part, fd);
}
