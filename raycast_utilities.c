/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:03:16 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 23:24:06 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->r_height)
	{
		x = 0;
		while (x < info->r_width)
		{
			info->img.data[y * info->r_width - x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		main_loop(t_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}
