/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 02:02:20 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 03:00:15 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		for_every_pixel(t_info *info)
{
	info->y = info->draw_start_y;
	while (info->y < info->draw_end_y)
	{
		info->d = (info->y - info->v_move_screen) * 256 - info->r_height * 128
												+ info->sprite_height * 128;
		info->tex_y_s = ((info->d * TEX_WIDTH) / info->sprite_height) / 256;
		info->color = info->texture[4][TEX_WIDTH * info->tex_y_s
															+ info->tex_x_s];
		if ((info->color & 0x00FFFFFF) != 0)
			info->buf[info->y][info->stripe] = info->color;
		info->y++;
	}
}

void		transform_sprite(t_info *info)
{
	info->inv_det = 1.0 / (info->plane_x * info->dir_y
									- info->dir_x * info->plane_y);
	info->transform_x = info->inv_det * (info->dir_y
				* info->sprite_x - info->dir_x * info->sprite_y);
	info->transform_y = info->inv_det * (-info->plane_y
				* info->sprite_x + info->plane_x * info->sprite_y);
	info->sprite_screen_x = (int)((info->r_width / 2)
					* (1 + info->transform_x / info->transform_y));
	info->v_move_screen = (int)(V_MOVE / info->transform_y);
}

void		calc_height_width_sprite(t_info *info)
{
	info->sprite_height = (int)fabs((info->r_height
										/ info->transform_y) / V_DIV);
	info->draw_start_y = -info->sprite_height / 2 + info->r_height / 2
												+ info->v_move_screen;
	if (info->draw_start_y < 0)
		info->draw_start_y = 0;
	info->draw_end_y = info->sprite_height / 2 + info->r_height / 2
												+ info->v_move_screen;
	if (info->draw_end_y >= info->r_height)
		info->draw_end_y = info->r_height - 1;
	info->sprite_width = (int)fabs((info->r_height
										/ info->transform_y) / U_DIV);
	info->draw_start_x = -info->sprite_width / 2 + info->sprite_screen_x;
	if (info->draw_start_x < 0)
		info->draw_start_x = 0;
	info->draw_end_x = info->sprite_width / 2 + info->sprite_screen_x;
	if (info->draw_end_x >= info->r_width)
		info->draw_end_x = info->r_width - 1;
}

void		sprite_screen(t_info *info)
{
	info->stripe = info->draw_start_x;
	while (info->stripe < info->draw_end_x)
	{
		info->tex_x_s = (int)((256 * (info->stripe - (-info->sprite_width / 2
			+ info->sprite_screen_x)) * TEX_WIDTH / info->sprite_width) / 256);
		if (info->transform_y > 0 && info->stripe > 0 &&
					info->stripe < info->r_width &&
					info->transform_y < info->z_buffer[info->stripe])
			for_every_pixel(info);
		info->stripe++;
	}
	info->sp_num++;
}

void		calc_sprites(t_info *info)
{
	int		sprite_order[info->count_sp];
	double	sprite_distance[info->count_sp];

	info->sp_num = 0;
	while (info->sp_num < info->count_sp)
	{
		sprite_order[info->sp_num] = info->sp_num;
		sprite_distance[info->sp_num] = ((info->pos_x
				- info->mapsp[info->sp_num][0]) * (info->pos_x
				- info->mapsp[info->sp_num][0]) + (info->pos_y
				- info->mapsp[info->sp_num][1]) * (info->pos_y
				- info->mapsp[info->sp_num][1]));
		info->sp_num++;
	}
	sort_sprites(sprite_order, sprite_distance, info->count_sp);
	info->sp_num = 0;
	while (info->sp_num < info->count_sp)
	{
		info->sprite_x = info->mapsp[sprite_order[info->sp_num]][0]
													- info->pos_x;
		info->sprite_y = info->mapsp[sprite_order[info->sp_num]][1]
													- info->pos_y;
		function(info);
	}
}
