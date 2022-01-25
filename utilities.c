/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:02:33 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/08 16:44:11 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		error_exit(char *error)
{
	printf("%s", error);
	exit(EXIT_SUCCESS);
}

int		check_flags(t_info *info)
{
	if (info->set.flag_r != 1 || info->set.flag_no != 1 ||
		info->set.flag_so != 1 || info->set.flag_we != 1 ||
		info->set.flag_ea != 1 || info->set.flag_s != 1 ||
		info->set.flag_f != 1 || info->set.flag_c != 1)
		return (0);
	return (1);
}

void	free_item(char **s)
{
	int i;

	i = 0;
	while (s && s[i])
		free(s[i++]);
	free(s);
}
