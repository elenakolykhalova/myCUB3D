/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:30:25 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/08 17:30:13 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_update(t_info *info)
{
	up_down(info);
	left_right(info);
	rotation_key_r(info);
	rotation_key_l(info);
	if (info->key_esc)
		exit(0);
}

int		key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 1;
	else if (key == K_A)
		info->key_a = 1;
	else if (key == K_S)
		info->key_s = 1;
	else if (key == K_D)
		info->key_d = 1;
	else if (key == K_ARROW_L)
		info->key_l = 1;
	else if (key == K_ARROW_R)
		info->key_r = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 0;
	else if (key == K_A)
		info->key_a = 0;
	else if (key == K_S)
		info->key_s = 0;
	else if (key == K_D)
		info->key_d = 0;
	else if (key == K_ARROW_L)
		info->key_l = 0;
	else if (key == K_ARROW_R)
		info->key_r = 0;
	return (0);
}

int		key_close_programm(void)
{
	exit(0);
}
