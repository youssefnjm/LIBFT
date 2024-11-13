/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-25 17:58:08 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-25 17:58:08 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in(char const *set, char s1)
{
	while (*set && s1 != *set)
		set++;
	return (*set == s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;

	if (!s1 || !set)
		return (ft_strdup(""));
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && in(set, s1[first]))
		first++;
	if (s1[first] == '\0')
		return (ft_strdup(""));
	while (last > first && in(set, s1[last - 1]))
		last--;
	return (ft_substr(s1, first, last - first));
}
