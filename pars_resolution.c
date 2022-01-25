/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:35:13 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 21:58:45 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_screen(t_info *info)
{
	mlx_get_screen_size(&info->r_check_w, &info->r_check_h);
	if (info->start_w > info->r_check_w)
		info->r_width = info->r_check_w;
	else
		info->r_width = info->start_w;
	if (info->start_h > info->r_check_h)
		info->r_height = info->r_check_h;
	else
		info->r_height = info->start_h;
	if (info->r_width < 300)
		info->r_width = 300;
	if (info->r_height < 150)
		info->r_height = 150;
}

int			resolution(t_info *info, char **tmp)
{
	int i;

	if (info->set.flag_r == 1)
		error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		error_exit("ОШИБКА В ПАРАМЕТРАХ РАЗРЕШЕНИЯ ЭКРАНА\n");
	info->start_w = ft_atoi(tmp[1]);
	info->start_h = ft_atoi(tmp[2]);
	if (info->start_w < 0 || info->start_h < 0)
		error_exit("ОТРИЦАТЕЛЬНЫЕ ЗНАЧЕНИЯ ЭКРАНА\n");
	check_screen(info);
	info->set.flag_r = 1;
	return (0);
}
