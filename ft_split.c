/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoujoum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-26 12:59:41 by ynoujoum          #+#    #+#             */
/*   Updated: 2024-10-26 12:59:41 by ynoujoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int		i;
	int		stp;

	i = 0;
	count = 0;
	stp = 0;
	while (s[i] != '\0')
	{
		stp = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (stp == 0)
			{
				stp = 1;
				count++;
			}
			i++;
		}
	}
	return (count);
}

static	int	ft_safe_malloc(char **words_v, int position, size_t len)
{
	int	i;

	i = 0;
	words_v[position] = malloc(len);
	if (!words_v[position])
	{
		while (i < position)
			free(words_v[i++]);
		free(words_v);
		return (1);
	}
	return (0);
}

static	int	ft_fill(char **word_v, char const *s, char c)
{
	int		position;
	size_t	len;

	position = 0;
	len = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len != 0)
		{
			if (ft_safe_malloc(word_v, position, len + 1))
				return (1);
			ft_strlcpy(word_v[position], s - len, len + 1);
		}
		position++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	num_word;
	char	**words_v;

	i = 0;
	if (!s)
		return (NULL);
	num_word = ft_count_words(s, c);
	words_v = malloc(sizeof(char *) * (num_word + 1));
	if (!words_v)
		return (NULL);
	words_v[num_word] = NULL;
	if (ft_fill(words_v, s, c))
		return (NULL);
	return (words_v);
}
