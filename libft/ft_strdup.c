/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:24:19 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/14 19:29:00 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
