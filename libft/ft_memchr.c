/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:23:52 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/13 21:42:35 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char b;

	a = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (*a == b)
			return (a);
		a++;
	}
	return (NULL);
}
