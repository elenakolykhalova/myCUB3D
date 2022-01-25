/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:25:30 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/13 18:06:28 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
		*a++ = *b++;
	return (dst);
}
