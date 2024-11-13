/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:16:18 by ynoujoum          #+#    #+#             */
/*   Updated: 2024/10/22 18:16:20 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	check_overflow(size_t n, int signe)
{
	if (n >= 9223372036854775807 && signe == 1)
		return (-1);
	if (n > 9223372036854775807 && signe == -1)
		return (0);
	return (3);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		signe;
	size_t	n;

	i = 0;
	n = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		if (check_overflow(n, signe) != 3)
			return (check_overflow(n, signe));
		result = result * 10 + (str[i++] - 48);
	}
	return (result * signe);
}
