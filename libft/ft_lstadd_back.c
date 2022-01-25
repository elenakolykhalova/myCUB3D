/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:54:22 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/20 13:17:27 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
