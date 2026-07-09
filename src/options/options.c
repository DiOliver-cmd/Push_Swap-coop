/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:21:35 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by masalaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_flag(char *arg, t_options *opt)
{
	if (ft_strncmp(arg, "--simple", -1) == ERR)
		opt->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", -1) == ERR)
		opt->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", -1) == ERR)
		opt->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", -1) == ERR)
		opt->strategy = STRAT_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", -1) == ERR)
		opt->bench_mode = SUC;
	else
		return (ERR);
	return (SUC);
}

int	parse_options(int argc, char *argv[], t_options *opt)
{
	int	i;
	int	j;

	opt->strategy = STRAT_ADAPTIVE;
	opt->bench_mode = ERR;
	opt->disorder = 0.0;
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (is_flag(argv[i], opt) == ERR)
		{
			argv[j] = argv[i];
			j++;
		}
		i++;
	}
	return (j);
}
