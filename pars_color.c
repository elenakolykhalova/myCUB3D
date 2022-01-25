/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:52:08 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 21:32:42 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		count_argument(char **tmp)
{
	int j;

	j = 0;
	while (tmp[j])
		j++;
	if (j != 2)
		error_exit("ОШИБКА В ПАРАМЕТРАХ ЦВЕТА\n");
}

static void		check_color_f(t_info *info, char **tmp)
{
	char	**color;
	int		i;

	if (info->set.flag_f == 1)
		error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
	color = ft_split(tmp[1], ',');
	i = 0;
	while (color[i])
		i++;
	if (i != 3)
		error_exit("ОШИБКА ЦВЕТА\n");
	count_argument(tmp);
	info->f_r = ft_atoi(color[0]);
	info->f_g = ft_atoi(color[1]);
	info->f_b = ft_atoi(color[2]);
	if (info->f_r < 0 || info->f_r > 255 || info->f_g < 0 ||
			info->f_g > 255 || info->f_b < 0 || info->f_b > 255)
		error_exit("ОШИБКА ЦВЕТА\n");
	info->f_rgb = create_trgb(0, info->f_r, info->f_g, info->f_b);
	info->set.flag_f = 1;
	free_item(color);
}

void			check_color(char *line, t_info *info, char **tmp, int i)
{
	char **color;

	if (ft_strnstr(line, "F ", ft_strlen(line)))
		check_color_f(info, tmp);
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
	{
		if (info->set.flag_c == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		count_argument(tmp);
		color = ft_split(tmp[1], ',');
		while (color[i])
			i++;
		if (i != 3)
			error_exit("ОШИБКА ЦВЕТА\n");
		info->c_r = ft_atoi(color[0]);
		info->c_g = ft_atoi(color[1]);
		info->c_b = ft_atoi(color[2]);
		if (info->c_r < 0 || info->c_r > 255 || info->c_g < 0 ||
			info->c_g > 255 || info->c_b < 0 || info->c_b > 255)
			error_exit("ОШИБКА ЦВЕТА\n");
		info->c_rgb = create_trgb(0, info->c_r, info->c_g, info->c_b);
		info->set.flag_c = 1;
		free_item(color);
	}
}
