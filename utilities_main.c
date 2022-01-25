/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:57:24 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 04:23:20 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		window(t_info info)
{
	info.move_speed = 0.05;
	info.rot_speed = 0.05;
	info.win = mlx_new_window(info.mlx, info.r_width, info.r_height, "MCARRY");
	info.img.img = mlx_new_image(info.mlx, info.r_width, info.r_height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
											&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0L >> 0, &key_close_programm, &info);
	mlx_loop(info.mlx);
}

void		main_texture(t_info *info)
{
	int i;
	int j;

	i = 0;
	if (!(info->texture = (int **)malloc(sizeof(int *) * 5)))
		error_exit("ОШИБКА\n");
	while (i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) *
													(TEX_HEIGHT * TEX_WIDTH))))
			error_exit("ОШИБКА\n");
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		main_buf(t_info *info)
{
	int		i;
	int		j;

	if (!(info->buf = (int **)malloc(sizeof(int *) * info->r_height)))
		error_exit("ОШИБКА\n");
	i = 0;
	while (i < info->r_height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * info->r_width)))
			error_exit("ОШИБКА\n");
		i++;
	}
	i = 0;
	while (i < info->r_height)
	{
		j = 0;
		while (j < info->r_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		read_file(char **argv, t_info *info)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("ФАЙЛ НЕ СУЩЕСТВУЕТ\n");
	if (read(fd, NULL, 0) == -1)
		error_exit("ЭТО ПАПКА\n");
	check_cub(argv[1]);
	while (get_next_line(fd, &line) > 0)
	{
		pars_options(line, info, 0);
		free(line);
	}
	pars_options(line, info, 0);
	free(line);
	if (get_next_line(fd, &line) == 0)
		if (info->set.flag_r != 1)
		{
			free(line);
			error_exit("ФАЙЛ ПУСТОЙ\n");
		}
	free(line);
	pars_map(info, ft_lstsize(info->list_map));
}
