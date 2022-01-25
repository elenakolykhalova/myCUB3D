/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 02:10:59 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 02:16:37 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_draw_texture(t_info *info)
{
	while (info->y < info->draw_end)
	{
		info->tex_y = (int)info->tex_pos & (TEX_HEIGHT - 1);
		info->tex_pos += info->step;
		if (info->side == 1)
		{
			if (info->step_y > 0)
				info->color = info->texture[0][TEX_WIDTH * info->tex_y
														+ info->tex_x];
			if (info->step_y < 0)
				info->color = info->texture[1][TEX_WIDTH * info->tex_y
														+ info->tex_x];
		}
		if (info->side == 0)
		{
			if (info->step_x > 0)
				info->color = info->texture[2][TEX_WIDTH * info->tex_y
														+ info->tex_x];
			if (info->step_x < 0)
				info->color = info->texture[3][TEX_WIDTH * info->tex_y
														+ info->tex_x];
		}
		info->buf[info->y][info->x] = info->color;
		info->y++;
	}
}

void	calc_draw_floor_ceiling_tex(t_info *info)
{
	info->y = 0;
	while (info->y < info->draw_start)
	{
		info->buf[info->y][info->x] = info->c_rgb;
		info->y++;
	}
	info->y = info->draw_start;
	calc_draw_texture(info);
	info->y = info->draw_end;
	while (info->y < info->r_height)
	{
		info->buf[info->y][info->x] = info->f_rgb;
		info->y++;
	}
}

void	perform_dda(t_info *info)
{
	while (info->hit == 0)
	{
		if (info->side_dist_x < info->side_dist_y)
		{
			info->side_dist_x += info->delta_dist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->side_dist_y += info->delta_dist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (info->map[info->map_y][info->map_x] == '1')
			info->hit = 1;
	}
}

void	step_x_y(t_info *info)
{
	if (info->ray_dir_x < 0)
	{
		info->step_x = -1;
		info->side_dist_x = (info->pos_x - info->map_x)
											* info->delta_dist_x;
	}
	else
	{
		info->step_x = 1;
		info->side_dist_x = (info->map_x + 1.0 - info->pos_x)
											* info->delta_dist_x;
	}
	if (info->ray_dir_y < 0)
	{
		info->step_y = -1;
		info->side_dist_y = (info->pos_y - info->map_y)
											* info->delta_dist_y;
	}
	else
	{
		info->step_y = 1;
		info->side_dist_y = (info->map_y + 1.0 - info->pos_y)
											* info->delta_dist_y;
	}
}

void	perp_wall_dist_draw_start_end(t_info *info)
{
	if (info->side == 0)
		info->perp_wall_dist = ((double)info->map_x - info->pos_x
									+ (1 - info->step_x) / 2) / info->ray_dir_x;
	else
		info->perp_wall_dist = ((double)info->map_y - info->pos_y
									+ (1 - info->step_y) / 2) / info->ray_dir_y;
	info->line_height = (int)(info->r_height / info->perp_wall_dist);
	info->draw_start = -info->line_height / 2 + info->r_height / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + info->r_height / 2;
	if (info->draw_end >= info->r_height)
		info->draw_end = info->r_height - 1;
	if (info->draw_end < 0)
		info->draw_end = info->r_height - 1;
}
