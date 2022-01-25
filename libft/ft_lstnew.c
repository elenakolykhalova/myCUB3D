/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:36:34 by mcarry            #+#    #+#             */
/*   Updated: 2020/11/18 22:36:43 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *connection;

	if (!(connection = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	connection->content = content;
	connection->next = NULL;
	return (connection);
}
