/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 by dilferre                                         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	Resolve o caso de exatamente 3 elementos com no maximo 2
	operacoes, sem nunca tocar a pilha b. Os 6 casos possiveis
	de ordenacao de 3 valores distintos sao cobertos pelas
	comparacoes abaixo (x = topo, y = meio, z = fundo).
*/
static void	sort_three(t_list *a)
{
	int	x;
	int	y;
	int	z;

	x = a->value;
	y = a->next->value;
	z = a->next->next->value;
	if (x < y && y < z)
		return ;
	if (x < y && y > z && x < z)
	{
		rra();
		sa();
	}
	else if (x > y && y < z && x < z)
		sa();
	else if (x < y && y > z && x > z)
		rra();
	else if (x > y && y < z && x > z)
		ra();
	else
	{
		sa();
		rra();
	}
}
void	sort_small(void)
{
	t_list	*a;
	int		size;

	a = *(get_stack_a());
	size = ft_lstsize(a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (a->value > a->next->value)
			sa();
		return ;
	}
	sort_three(a);
}
