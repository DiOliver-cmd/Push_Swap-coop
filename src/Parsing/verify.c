/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalaib <masalaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:18:07 by masalaib          #+#    #+#             */
/*   Updated: 2026/07/01 16:57:59 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	verify_is_digit_word(int argc, char *argv[])
{
	int	i;

	while (argc > 0)
	{
		i = 0;
		if (argv[argc][i] == '-')
			i++;
		if (argv[argc][i] == '\0')
			return (ERR);
		while (argv[argc][i] != '\0')
		{
			if (ft_isdigit(argv[argc][i]) == ERR)
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

	i = 1;
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
