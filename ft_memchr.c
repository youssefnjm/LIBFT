/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 10:53:30 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-23 10:53:30 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			if (str[i] == (const unsigned char)c)
			{
				return ((void *)(str + i));
			}
			i++;
		}
	}
	return (0);
}
