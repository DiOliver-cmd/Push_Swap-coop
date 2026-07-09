/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:54:19 by dilferre          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reset_stack(void)
{
	t_list	*current;
	t_list	*smallest;
	int		index;

	index = 0;
	while (1)
	{
		current = *get_stack_a();
		smallest = NULL;
		while (current)
		{
			if (current->content == NULL
				&& (!smallest || current->value < smallest->value))
				smallest = current;
			current = current->next;
		}
		if (!smallest)
			break ;
		smallest->value = index++;
		smallest->content = (void *)1;
	}
}

static void	node_to_b(double range, double total)
{
	t_list	*list;
	double	position;

	list = *get_stack_a();
	position = 0;
	while (list != NULL && (((double)list->value) > range))
	{
		list = list->next;
		position++;
	}
	rotate_to_position((int)position, (int)total);
	pb();
}

void	sort_medium(void)
{
	double	total;
	double	range;

	reset_stack();
	range = 1.3 * my_sqrt(ft_lstsize(*get_stack_a()));
	total = (double)ft_lstsize(*get_stack_a());
	while (total > 1)
	{
		node_to_b(range, total);
		total = (double)ft_lstsize(*get_stack_a());
		range += 1;
	}
	merge_b_to_a();
	final_rotation();
}