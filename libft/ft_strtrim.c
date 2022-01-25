/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:19 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/19 00:26:19 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*str;

	str = (char *)s1;
	if (!str || !set)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len && ft_strchr(set, str[len]))
		len--;
	return (ft_substr(str, 0, len + 1));
}
