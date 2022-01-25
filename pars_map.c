/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:55:34 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 04:24:50 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_map(char *line, t_info *info)
{
	int i;

	i = 0;
	if (!check_flags(info))
		error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
	while (line[i])
	{
		if (ft_strchr(" 012NSWE", line[i]) > 0)
			i++;
		else
			error_exit("ОШИБКА В ПАРАМЕТРАХ КАРТЫ\n");
	}
	info->set.flag_map_st = 1;
	ft_lstadd_back(&info->list_map, ft_lstnew(ft_strdup(line)));
}

void		check_map_error(char *line, t_info *info)
{
	int i;

	i = 0;
	if (!line[i] && !info->set.flag_map_st)
		return ;
	else
		error_exit("ОШИБКА КАРТЫ\n");
}

char		**pars_map(t_info *info, int size)
{
	int		i;
	t_list	*tmp;

	if (!(info->map = ft_calloc(size + 1, sizeof(char *))))
		error_exit("ОШИБКА\n");
	i = -1;
	tmp = info->list_map;
	while (tmp)
	{
		info->map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (info->map);
}

char		**ft_copy_map(t_info *info, int size)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(*copy) * (size + 1));
	i = -1;
	while (info->map[++i])
	{
		copy[i] = ft_strdup(info->map[i]);
	}
	copy[i] = 0;
	return (copy);
}

int			flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (1);
	if (map[y][x] == ' ')
		error_exit("НЕВАЛИДНАЯ КАРТА\n");
	map[y][x] = '1';
	return (flood_fill(map, x + 1, y) &&
		flood_fill(map, x - 1, y) &&
		flood_fill(map, x, y + 1) &&
		flood_fill(map, x, y - 1) &&
		flood_fill(map, x + 1, y + 1) &&
		flood_fill(map, x + 1, y - 1) &&
		flood_fill(map, x - 1, y - 1) &&
		flood_fill(map, x - 1, y + 1));
}
