/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:06:37 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 02:14:51 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tex(t_info *info)
{
	if (info->side == 0)
		info->wall_x = info->pos_y + info->perp_wall_dist * info->ray_dir_y;
	else
		info->wall_x = info->pos_x + info->perp_wall_dist * info->ray_dir_x;
	info->wall_x -= floor((info->wall_x));
	info->tex_x = (int)(info->wall_x * (double)TEX_WIDTH);
	if (info->side == 0 && info->ray_dir_x > 0)
		info->tex_x = TEX_WIDTH - info->tex_x - 1;
	if (info->side == 1 && info->ray_dir_y < 0)
		info->tex_x = TEX_WIDTH - info->tex_x - 1;
	info->step = 1.0 * TEX_HEIGHT / info->line_height;
	info->tex_pos = (info->draw_start - info->r_height / 2
										+ info->line_height / 2) * info->step;
}

void		calc(t_info *info)
{
	info->x = 0;
	while (info->x < info->r_width)
	{
		info->camera_x = 2 * info->x / (double)info->r_width - 1;
		info->ray_dir_x = info->dir_x + info->plane_x * info->camera_x;
		info->ray_dir_y = info->dir_y + info->plane_y * info->camera_x;
		info->map_x = (int)info->pos_x;
		info->map_y = (int)info->pos_y;
		info->delta_dist_x = fabs(1 / info->ray_dir_x);
		info->delta_dist_y = fabs(1 / info->ray_dir_y);
		info->hit = 0;
		step_x_y(info);
		perform_dda(info);
		perp_wall_dist_draw_start_end(info);
		draw_tex(info);
		calc_draw_floor_ceiling_tex(info);
		info->z_buffer[info->x] = info->perp_wall_dist;
		info->x++;
	}
	calc_sprites(info);
}
