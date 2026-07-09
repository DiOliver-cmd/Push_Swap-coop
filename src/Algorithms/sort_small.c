/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <dilferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:10:27 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/05 20:00:09 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_list *a)
{
	int	x;
	int	y;
	int	z;

	x = a->value;
	y = a->next->value;
	z = a->next->next->value;
	if (x < y && y < z)
		return ;
	if (x < y && y > z && x < z)
	{
		rra();
		sa();
	}
	else if (x > y && y < z && x < z)
		sa();
	else if (x < y && y > z && x > z)
		rra();
	else if (x > y && y < z && x > z)
		ra();
	else
	{
		sa();
		rra();
	}
}

void	sort_small(void)
{
	t_list	*a;
	int		size;

	a = *(get_stack_a());
	size = ft_lstsize(a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (a->value > a->next->value)
			sa();
		return ;
	}
	sort_three(a);
}
