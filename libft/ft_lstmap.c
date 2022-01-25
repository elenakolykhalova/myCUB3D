/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:46:16 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/20 13:22:30 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *nachalo;

	if (!lst)
		return (NULL);
	if (!(newlist = ft_lstnew(f(lst->content))))
		return (NULL);
	nachalo = newlist;
	lst = lst->next;
	while (lst)
	{
		if (!(newlist->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&nachalo, del);
			return (NULL);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (nachalo);
}
