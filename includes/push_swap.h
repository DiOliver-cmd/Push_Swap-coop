/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/06/23 14:28:48 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR 0
# define SUC 1
# define MAX_LEN_WORD 11

# include "../../libft/libft.h"
# include <unistd.h>

typedef struct s_stacks
{
	t_node	*a;// Ponteiro para o topo da Pilha A
	t_node	*b;// Ponteiro para o topo da Pilha B
	int	size_a;// Tamanho atual da Pilha A
	int	size_b;// Tamanho atual da Pilha B
	double	disorder;// Métrica de desordem
}	t_stacks;

double	count_disorder(t_node *stack_a);
void	dispatch_algorithm(t_node **stack_a, t_node **stack_b, t_options opt);

#endif
