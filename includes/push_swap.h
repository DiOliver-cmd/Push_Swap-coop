/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:08 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR 0
# define SUC 1
# define MAX_LEN_WORD 11

# include "../../libft/libft.h"
# include "stdio.h"

typedef struct s_node
{
	int				value;//inteiro recebido
	int				index;//rank do n após ordenado
	struct s_node	*next;//ponteiro para o proximo nó
	struct s_node	*prev;//ponteiro para o nó anterior
}	t_node;

double	count_disorder(t_node *stack_a);
void	dispatch_algorithm(t_node **stack_a, t_node **stack_b, t_options opt);

#endif
