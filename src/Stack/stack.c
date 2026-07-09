/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:21:56 by marvin            #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	**get_stack_a(void)
{
	static t_list	*stack_a;

	return (&stack_a);
}

t_list	**get_stack_b(void)
{
	static t_list	*stack_b;

	return (&stack_b);
}

static void	nothing(void *content)
{
	(void)content;
}

void	my_exit(int value)
{
	ft_lstclear(get_stack_a(), nothing);
	ft_lstclear(get_stack_b(), nothing);
	if (value == 0)
		write(1, "Error\n", 6);
	exit(0);
}
