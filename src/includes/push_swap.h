/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/06/22 11:16:28 by dilferre         ###   ########.fr       */
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
	int				value;
	struct s_node	*next;
}	t_node;

#endif
