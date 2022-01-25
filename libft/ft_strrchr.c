/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:58:55 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/11 19:04:41 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len--)
	{
		if (*(s + len) == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
