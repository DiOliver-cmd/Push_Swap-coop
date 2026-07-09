/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:54:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/07 18:00:00 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	my_sqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

void	rotate_to_position(int position, int total)
{
	if (position <= total / 2)
	{
		while (position-- > 0)
			ra();
	}
	else
	{
		while (position++ < total)
			rra();
	}
}

static int	find_insert_position(int value)
{
	t_list	*current;
	int		position;
	int		best_position;
	int		best_value;

	current = *get_stack_a();
	position = 0;
	best_position = -1;
	best_value = 0;
	while (current)
	{
		if (current->value > value
			&& (best_position == -1 || current->value < best_value))
		{
			best_position = position;
			best_value = current->value;
		}
		current = current->next;
		position++;
	}
	if (best_position == -1)
		best_position = position;
	return (best_position);
}

void	merge_b_to_a(void)
{
	int	value;
	int	total;
	int	position;

	while (*get_stack_b() != NULL)
	{
		value = (*get_stack_b())->value;
		total = ft_lstsize(*get_stack_a());
		position = find_insert_position(value);
		rotate_to_position(position, total);
		pa();
	}
}

void	final_rotation(void)
{
	t_list	*current;
	int		position;
	int		min_position;
	int		min_value;

	current = *get_stack_a();
	position = 0;
	min_position = 0;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	rotate_to_position(min_position, ft_lstsize(*get_stack_a()));
}
