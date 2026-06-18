/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_inval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:30:19 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/18 18:21:24 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int	check_int(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	check_str(const char *str)
{
	int		sign;
	int		num;
	long	count;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	count = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		count = (count * 10) + (*str - '0');
		if (count > 2147483648L)
			break ;
		str++;
		num += 1;
	}
	if ((num <= 0) || (*str))
		return (0);
	if (check_int(count * sign))
		return (1);
	return (0);
}

