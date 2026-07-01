/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:21:06 by marvin            #+#    #+#             */
/*   Updated: 2026/07/01 16:23:30 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	all_verifies(int argc, char *argv[])
{
	if (
		verify_is_digit_word(argc, argv) == ERR
		|| repeated_word(argc, argv) == ERR
		|| verify_max_len(argc, argv) == ERR
	)
		return (ERR);
	return (SUC);
}

int	main(int argc, char *argv[])
{
	t_options	opt;
	int			n;

	if (argc <= 1)
		return (0);
	n = parse_options(argc, argv, &opt);
	if (n <= 1)
		return (0);
	if (
		all_verifies(n - 1, argv) == ERR
		|| iniciate_stack_a(n, argv) == ERR
	)
		my_exit(0);
	dispatch_algorithm(&opt);
	my_exit(1);
}
