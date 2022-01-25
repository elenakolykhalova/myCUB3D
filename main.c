/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:06:34 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 02:59:49 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_info	info;
	char	**copy_map;

	copy_map = NULL;
	ft_memset(&info, 0, sizeof(info));
	info.mlx = mlx_init();
	read_file(argv, &info);
	if (!(info.z_buffer = malloc(sizeof(double *) * info.r_width)))
		error_exit("ОШИБКА\n");
	init_plr(&info, 0, 1);
	copy_map = ft_copy_map(&info, ft_lstsize(info.list_map));
	flood_fill(copy_map, (int)info.pos_x, (int)info.pos_y);
	free_item(copy_map);
	main_buf(&info);
	main_texture(&info);
	load_texture(&info);
	if (argc >= 3)
		pars_save(argv[2], &info);
	window(info);
}
