/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:11:23 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/08 17:00:33 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_array(char **tmp, int count)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	if (i != count)
		error_exit("ОШИБКА В КОЛИЧЕСТВЕ АРГУМЕНТОВ\n");
}

static void	texture_so_s(char *line, t_info *info, char **tmp)
{
	if (ft_strnstr(line, "EA ", ft_strlen(line)))
	{
		if (info->set.flag_ea == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		info->ea = ft_strdup(tmp[1]);
		info->set.flag_ea = 1;
	}
	else if (ft_strnstr(line, "SO ", ft_strlen(line)))
	{
		if (info->set.flag_so == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		info->so = ft_strdup(tmp[1]);
		info->set.flag_so = 1;
	}
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
	{
		if (info->set.flag_s == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		info->s = ft_strdup(tmp[1]);
		info->set.flag_s = 1;
	}
}

void		texture(char *line, t_info *info, char **tmp)
{
	check_array(tmp, 2);
	if (ft_strnstr(line, "NO ", ft_strlen(line)))
	{
		if (info->set.flag_no == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		info->no = ft_strdup(tmp[1]);
		info->set.flag_no = 1;
	}
	else if (ft_strnstr(line, "WE ", ft_strlen(line)))
	{
		if (info->set.flag_we == 1)
			error_exit("ОШИБКА В ПАРАМЕТРАХ\n");
		info->we = ft_strdup(tmp[1]);
		info->set.flag_we = 1;
	}
	else if (ft_strnstr(line, "SO ", ft_strlen(line)) ||
			ft_strnstr(line, "S ", ft_strlen(line)) ||
			ft_strnstr(line, "EA ", ft_strlen(line)))
		texture_so_s(line, info, tmp);
}
