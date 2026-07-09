/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 00:18:56 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/01 16:18:16 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	calc_desorder(void)
{
	t_list	*list;
	t_list	*temp;
	double	count;
	double	error;

	list = *(get_stack_a());
	count = 0;
	error = 0;
	while (list != NULL)
	{
		temp = list->next;
		while (temp != NULL)
		{
			if (list->value > temp->value)
				error++;
			count++;
			temp = temp->next;
		}
		list = list->next;
	}
	if (count == 0)
		return (0.0);
	return (error / count);
}

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}
