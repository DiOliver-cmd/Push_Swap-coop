/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:04:31 by marvin            #+#    #+#             */
/*   Updated: 2026/06/29 00:17:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	iniciate_stack_a(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	*temp;
	long	value;
	int		i;

	i = 1;
	stack_a = get_stack_a();
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value != (int)value)
			return (ERR);
		temp = ft_lstnew(NULL, value);
		if (!temp)
			return (ERR);
		ft_lstadd_back(stack_a, temp);
		i++;
	}
	return (SUC);
}
