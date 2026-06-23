/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:25:14 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/23 14:41:16 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double    count_disorder(t_stacks *stack_a)
{
  int mistakes;
  int total_pairs;
  t_node  *i;
  t_node  *j;

  mistakes = 0;
  total_pairs = 0;
  i = stack_a;
  while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            total_pairs++;
            if (i->value > j->value)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
        return (0.0);
    return ((double)mistakes / total_pairs);
}

void	dispatch_algorithm(t_node **stack_a, t_node **stack_b, t_options opt)
{
	double	disorder;

	if (opt.strategy == START_SIMPLE)
		sort_simple(stack_a, stack_b);
	else if (opt.strategy == STRAT_MEDIUM)
		sort_medium(stack_a, stack_b);
	else if (opt.strategy == STRAT_COMPLEX)
		sort_complex(stack_a, stack_b);
	else
	{
		disorder = count_disorder(*stack_a);

		if (disorder < 0.2)
			sort_simples(stack_a, stack_b);
		else if (disorder < 0.5)
			sort_medium(stack_a, stack_b);
		else
			sort_complex(stack_a, stack_b);
	}
}
