/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:21:56 by marvin            #+#    #+#             */
/*   Updated: 2026/06/29 00:52:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	**get_stack_a(void)
{
	static t_list	*stack_a = NULL;

	return (&stack_a);
}

t_list	**get_stack_b(void)
{
	static t_list	*stack_b = NULL;

	return (&stack_b);
}

// Function to help in tests
void	set_stack_a(t_list *new_stack)
{
	*(get_stack_a()) = new_stack;
}

void	nothing(void *content)
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
