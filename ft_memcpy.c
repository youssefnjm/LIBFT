/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.f>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-24 14:05:49 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-24 14:05:49 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*from;
	unsigned char		*to;
	size_t				i;

	if (src == dst)
		return ((void *)dst);
	if (!dst && !src)
		return (NULL);
	i = 0;
	from = (const unsigned char *)src;
	to = (unsigned char *)dst;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (to);
}
