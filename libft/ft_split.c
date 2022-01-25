/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:02:32 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/21 17:18:02 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		if (*str != c)
		{
			while (*str != c && *str)
				str++;
			count++;
		}
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char		*trim(char *s, char c)
{
	char *str;

	str = s;
	while (*str == c && *str)
		str++;
	return (str);
}

static char		**clean(char **ar)
{
	size_t i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	*str;
	size_t	words;
	char	**array;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s)
		return (NULL);
	str = (char *)s;
	words = word_count(str, c);
	if (!(array = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++i < words)
	{
		str = trim(str, c);
		if (!(array[i] = malloc(sizeof(char) * (word_len(str, c) + 1))))
			clean(array);
		j = 0;
		while (*str != c && *str != '\0')
			array[i][j++] = *str++;
		array[i][j] = '\0';
	}
	array[i] = NULL;
	return (array);
}
