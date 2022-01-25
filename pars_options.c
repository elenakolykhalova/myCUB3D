/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:09:21 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 04:22:13 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprites_calloc(t_info *info)
{
	info->sp_num = 0;
	if (!(info->mapsp = ft_calloc((info->count_sp + 1), sizeof(double *))))
		error_exit("ОШИБКА\n");
	while (info->sp_num < info->count_sp)
	{
		if (!(info->mapsp[info->sp_num] = ft_calloc(2, sizeof(double))))
			error_exit("ОШИБКА\n");
		info->sp_num++;
	}
}

void		init_sprites(t_info *info, int i, int j)
{
	init_sprites_calloc(info);
	i = 0;
	info->sp_num = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '2')
			{
				info->mapsp[info->sp_num][0] = j + 0.5;
				info->mapsp[info->sp_num][1] = i + 0.5;
				info->sp_num++;
			}
			j++;
		}
		i++;
	}
}

void		pars_options(char *line, t_info *info, int i)
{
	char	**tmp;
	char	**color;

	color = NULL;
	tmp = ft_split(line, ' ');
	if (ft_strnstr(line, "R ", ft_strlen(line)))
		resolution(info, tmp);
	else if (ft_strnstr(line, "NO ", ft_strlen(line)) ||
			ft_strnstr(line, "WE ", ft_strlen(line)) ||
			ft_strnstr(line, "EA ", ft_strlen(line)) ||
			ft_strnstr(line, "SO ", ft_strlen(line)) ||
			ft_strnstr(line, "S ", ft_strlen(line)))
		texture(line, info, tmp);
	else if (ft_strnstr(line, "F ", ft_strlen(line)) ||
			ft_strnstr(line, "C ", ft_strlen(line)))
	{
		check_color(line, info, tmp, 0);
		free_item(color);
	}
	else if (line[i] && line[i] != '\n')
		check_map(line, info);
	else
		check_map_error(line, info);
	free_item(tmp);
}
