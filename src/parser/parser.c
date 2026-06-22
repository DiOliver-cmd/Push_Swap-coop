/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:07 by masalaib          #+#    #+#             */
/*   Updated: 2026/06/18 20:20:49 by masalaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	verify_is_digit_word(int argc, char *argv[])
{
	int	i;

	while (argc > 0)
	{
		i = 0;
		while (argv[argc][i] != '\0')
		{
			printf("argv[argc][i]: %c\n", argv[argc][i]);
			if (ft_isalpha(argv[argc][i]) == ERR)
				return (ERR);
			i++;
		}
		argc--;
	}
	return (SUC);
}

int	repeated_word(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i <= argc)
	{
		j = i + 1;
		while (j <= argc)
		{
			if (ft_strncmp(argv[i], argv[j], -1) == ERR)
				return (ERR);
			j++;
		}
		i++;
	}
	return (SUC);
}

int	verify_max_len(int argc, char *argv[])
{
	while (argc > 0)
	{
		if (ft_strlen(argv[argc]) > MAX_LEN_WORD)
			return (ERR);
		argc--;
	}
	return (SUC);
}

int	verify_duplicate(t_node *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->value == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}


