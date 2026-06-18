/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:44:45 by dilferre          #+#    #+#             */
/*   Updated: 2026/05/28 17:36:09 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	c;
	long	nbr;

	nbr = n;
	c = ft_count(nbr);
	itoa = (char *)malloc(sizeof(char) * (c + 1));
	if (!itoa)
		return (NULL);
	itoa[c] = '\0';
	if (nbr == 0)
		itoa[0] = '0';
	if (nbr < 0)
	{
		itoa[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		itoa[--c] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (itoa);
}
