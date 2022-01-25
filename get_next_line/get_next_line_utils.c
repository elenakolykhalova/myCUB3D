/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:57:36 by mcarry            #+#    #+#             */
/*   Updated: 2020/12/26 16:31:16 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*rez;
	size_t	i;
	size_t	j;

	j = -1;
	i = ft_strlen(s1);
	if (!(rez = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (++j < i)
		rez[j] = s1[j];
	rez[j] = '\0';
	return (rez);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char		*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + len));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
