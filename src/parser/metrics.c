/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metrics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:25:14 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/22 13:25:31 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double    count_disorder(t_node *stack_a)
{
  int mistakes;
  int total_pairs;
  t_node  *i;
  t_node  *j;

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
