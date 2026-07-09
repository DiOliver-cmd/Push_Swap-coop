/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:19 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/07 15:30:00 by dilferre          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR 0
# define SUC 1
# define MAX_LEN_WORD 11

# include "../libft/libft.h"
# include <unistd.h>

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

typedef struct s_node_costs
{
	int	ca_up;
	int	ca_down;
	int	cb_up;
	int	cb_down;
}	t_node_costs;

typedef struct s_best_func_args
{
	int	val;
	int	*bp;
	int	*mp;
	int	*i;
}	t_best_func_args;

typedef struct s_cost
{
	int	idx_a;
	int	cost_a;
	int	dir_a;
	int	cost_b;
	int	dir_b;
	int	total;
}	t_cost;

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
	int	bench;
}	t_data;

/* verificacao de args */
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

/* dados / opcoes */
t_data	*get_data(void);
int		parse_options(int argc, char *argv[], t_options *opt);

/* algoritmo */
void	dispatch_algorithm(t_options *opt);
void	sort_simple(void);
void	sort_medium(void);
void	sort_complex(void);
void	sort_small(void);

/* helpers internos do sort_medium (compartilhados entre 2 arquivos) */
double	my_sqrt(int n);
void	rotate_to_position(int position, int total);
void	merge_b_to_a(void);
void	final_rotation(void);

/* helpers internos do sort_complex (compartilhados entre 2 arquivos) */
int		find_target_generic(t_list *stack, int value, int fallback);
void	do_moves(int cost_a, int dir_a, int cost_b, int dir_b);
void	try_same_dir(t_cost *best, int idx, t_node_costs *c, int dir);
void	try_mixed_dir(t_cost *best, int idx, t_node_costs *c, int dir_a);
void	eval_node(t_cost *best, int idx, int value, int size_a);
void	eval_node_b(t_cost *best, int idx, int value, int size_b);

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

// Print
char	*strategy_name(t_strategy s);
char	*complexity_name(t_strategy s);
int		total_ops(t_data *d);
void	put_float(double n, int fd);
void	show_bench(t_options *opt);

#endif
