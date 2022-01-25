/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:06:31 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/14 15:49:14 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (i + j < len && str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
