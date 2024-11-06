/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.f>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 19:33:57 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-23 19:33:57 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (len == 0 || dst == src)
		return ((void *)dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		len--;
		*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	return ((void *)dst);
}
