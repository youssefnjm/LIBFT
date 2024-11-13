/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-26 15:38:10 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-26 15:38:10 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (i);
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*min_int(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		i;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (min_int());
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	count = ft_count(n) + i;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (i == 1)
		str[0] = '-';
	while ((count-- - i) != 0)
	{
		str[count] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
