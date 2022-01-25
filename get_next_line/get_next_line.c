/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:56:51 by mcarry            #+#    #+#             */
/*   Updated: 2020/12/27 14:13:29 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*check_after_n(char **after_n, char **line)
{
	char		*p_n;
	char		*tmp;

	p_n = NULL;
	if (*after_n)
	{
		if ((p_n = ft_strchr(*after_n, '\n')))
		{
			*p_n = '\0';
			tmp = *after_n;
			*line = ft_strdup(*after_n);
			*after_n = ft_strdup(++p_n);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*after_n);
			free(*after_n);
			*after_n = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

int			get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			reader;
	char		*p_n;
	static char *after_n;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line) || read(fd, buffer, 0) == -1)
		return (-1);
	p_n = check_after_n(&after_n, line);
	while (!p_n && (reader = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[reader] = '\0';
		if ((p_n = ft_strchr(buffer, '\n')))
		{
			*p_n = '\0';
			p_n++;
			after_n = ft_strdup(p_n);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	return ((after_n) ? 1 : 0);
}
