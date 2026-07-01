/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/01 16:50:59 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR 0
# define SUC 1
# define MAX_LEN_WORD 11

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_options
{
	t_strategy	strategy;
	t_strategy	used;
	int			bench_mode;
	double		disorder;
}	t_options;

typedef struct s_data
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_data;

/* verificação de args */
int		verify_is_digit_word(int argc, char *argv[]);
int		repeated_word(int argc, char *argv[]);
int		verify_max_len(int argc, char *argv[]);

/* stacks */
t_list	**get_stack_a(void);
t_list	**get_stack_b(void);
int		iniciate_stack_a(int argc, char *argv[]);
void	my_exit(int value);

/* utils */
long	ft_atol(const char *nptr);
double	calc_desorder(void);

/* dados / opções */
t_data		*get_data(void);
t_options	*get_options(void);
int			parse_options(int argc, char *argv[], t_options *opt);

/* algoritmo */
void	dispatch_algorithm(t_options *opt);
void	show_bench(t_options *opt);
void	sort_simple(void);
void	sort_medium(void);
void	sort_complex(void);

/* movimentos */
void	sa(void);
void	sb(void);
void	ss(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rr(void);
void	rra(void);
void	rrb(void);
void	rrr(void);

#endif
