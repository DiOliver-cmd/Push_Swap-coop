/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:57:51 by dilferre          #+#    #+#             */
/*   Updated: 2026/05/27 16:07:59 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**ft_cmatrix(char **matrix, size_t j)
{
	while (j > 0)
	{
		j--;
		free(matrix[j]);
	}
	free(matrix);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **msplit, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			msplit[j] = ft_substr(s, start, i - start);
			if (!msplit[j])
				return (ft_cmatrix(msplit, j));
			j++;
		}
	}
	msplit[j] = NULL;
	return (msplit);
}

char	**ft_split(char const *s, char c)
{
	char	**msplit;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wcount(s, c);
	msplit = (char **)malloc(sizeof(char *) * (words + 1));
	if (!msplit)
		return (NULL);
	return (ft_fill(s, c, msplit, words));
}
