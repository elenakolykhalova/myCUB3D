/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:26:22 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/20 13:19:06 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (size);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
