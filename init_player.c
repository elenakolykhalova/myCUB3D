/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:02:06 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 13:50:31 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_plr_south(t_info *info, int i, int j)
{
	info->pos_x = j + 0.5;
	info->pos_y = i + 0.5;
	info->dir_x = 0;
	info->dir_y = 1;
	info->plane_x = 0.66;
	info->plane_y = 0;
}

static void		init_plr_north(t_info *info, int i, int j)
{
	info->pos_x = j + 0.5;
	info->pos_y = i + 0.5;
	info->dir_x = 0;
	info->dir_y = -1;
	info->plane_x = -0.66;
	info->plane_y = 0;
}

static void		init_plr_west(t_info *info, int i, int j)
{
	info->pos_x = j + 0.5;
	info->pos_y = i + 0.5;
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
}

static void		init_plr_east(t_info *info, int i, int j)
{
	info->pos_x = j + 0.5;
	info->pos_y = i + 0.5;
	info->dir_x = 1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = -0.66;
}

void			init_plr(t_info *info, int i, int j)
{
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '2')
				info->count_sp++;
			if (info->map[i][j] == 'S')
				init_plr_south(info, i, j);
			if (info->map[i][j] == 'N')
				init_plr_north(info, i, j);
			if (info->map[i][j] == 'W')
				init_plr_west(info, i, j);
			if (info->map[i][j] == 'E')
				init_plr_east(info, i, j);
			j++;
			count_plr(info);
		}
		i++;
	}
	init_sprites(info, i, j);
}
