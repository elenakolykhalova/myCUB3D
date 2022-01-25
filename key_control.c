/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:16:48 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 23:41:39 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_down(t_info *info)
{
	if (info->key_w)
	{
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x +
							info->dir_x * info->move_speed)] != '1')
			info->pos_x += info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_y + info->dir_y *
							info->move_speed)][(int)(info->pos_x)] != '1')
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (info->key_s)
	{
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x -
							info->dir_x * info->move_speed)] != '1')
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->map[(int)(info->pos_y - info->dir_y *
							info->move_speed)][(int)(info->pos_x)] != '1')
			info->pos_y -= info->dir_y * info->move_speed;
	}
}

void	left_right(t_info *info)
{
	if (info->key_a)
	{
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x +
							info->plane_x * info->move_speed)] != '1')
			info->pos_x += info->plane_x * info->move_speed;
		if (info->map[(int)(info->pos_y + info->plane_y *
							info->move_speed)][(int)(info->pos_x)] != '1')
			info->pos_y += info->plane_y * info->move_speed;
	}
	if (info->key_d)
	{
		if (info->map[(int)(info->pos_y)][(int)(info->pos_x -
							info->plane_x * info->move_speed)] != '1')
			info->pos_x -= info->plane_x * info->move_speed;
		if (info->map[(int)(info->pos_y - info->plane_y *
							info->move_speed)][(int)(info->pos_x)] != '1')
			info->pos_y -= info->plane_y * info->move_speed;
	}
}

void	rotation_key_r(t_info *info)
{
	if (info->key_r)
	{
		info->olddir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed) -
									info->dir_y * sin(-info->rot_speed);
		info->dir_y = info->olddir_x * sin(-info->rot_speed) +
									info->dir_y * cos(-info->rot_speed);
		info->oldplane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rot_speed) -
									info->plane_y * sin(-info->rot_speed);
		info->plane_y = info->oldplane_x * sin(-info->rot_speed) +
									info->plane_y * cos(-info->rot_speed);
	}
}

void	rotation_key_l(t_info *info)
{
	if (info->key_l)
	{
		info->olddir_x = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rot_speed) -
										info->dir_y * sin(info->rot_speed);
		info->dir_y = info->olddir_x * sin(info->rot_speed) +
										info->dir_y * cos(info->rot_speed);
		info->oldplane_x = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rot_speed) -
										info->plane_y * sin(info->rot_speed);
		info->plane_y = info->oldplane_x * sin(info->rot_speed) +
										info->plane_y * cos(info->rot_speed);
	}
}
