/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:34:05 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/07 13:55:20 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_cub(char *argv)
{
	int i;

	i = ft_strlen(argv);
	if (!(ft_strnstr(&argv[i - 4], ".cub", ft_strlen(argv))))
		error_exit("НЕВЕРНОЕ РАCШИРЕНИЕ\n");
}

void		count_plr(t_info *info)
{
	int i;
	int j;

	i = 0;
	info->count_plr = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S' ||
					info->map[i][j] == 'E' || info->map[i][j] == 'W')
				info->count_plr++;
			j++;
		}
		i++;
	}
	if (info->count_plr > 1)
		error_exit("СЛИШКОМ МНОГО ИГРОКОВ\n");
}
