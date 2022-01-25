/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:23:55 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/08 20:43:41 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			j;
	size_t		lendst;

	i = 0;
	j = 0;
	lendst = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	lendst = i;
	while (i < (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (lendst < size)
		dst[i] = '\0';
	return (ft_strlen(src) + lendst);
}
