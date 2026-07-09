/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:34:38 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/01 16:34:43 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_top(t_list **from, t_list **to)
{
	t_list	*top;

	if (*from == NULL)
		return ;
	top = *from;
	*from = top->next;
	top->next = *to;
	*to = top;
}

void	pa(void)
{
	move_top(get_stack_b(), get_stack_a());
	get_data()->pa++;
	write(1, "pa\n", 3);
}

void	pb(void)
{
	move_top(get_stack_a(), get_stack_b());
	get_data()->pb++;
	write(1, "pb\n", 3);
}
