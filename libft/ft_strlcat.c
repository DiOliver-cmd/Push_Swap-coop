/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:55:58 by dilferre          #+#    #+#             */
/*   Updated: 2026/05/25 19:29:23 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	m_dest;
	size_t	m_src;
	size_t	i;

	m_src = ft_strlen(src);
	m_dest = 0;
	while (dest[m_dest] && m_dest < n)
		m_dest++;
	if (m_dest >= n)
		return (n + m_src);
	i = 0;
	while (src[i] && (m_dest + i + 1) < n)
	{
		dest[m_dest + i] = src[i];
		i++;
	}
	dest[m_dest + i] = '\0';
	return (m_dest + m_src);
}
