/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:53:44 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 04:21:33 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		header_bmp_one(t_info *info, unsigned char *bmp)
{
	int		offset;
	int		size;
	int		h2;
	int		pad;

	info->r_width = info->start_w;
	pad = info->r_width % 4;
	offset = 54;
	size = 54 + ((info->r_width * 3) + pad) * info->r_height;
	h2 = 40;
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)(size);
	bmp[3] = (unsigned char)(size >> 8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	bmp[10] = (unsigned char)(offset);
	bmp[14] = (unsigned char)(h2);
}

static void		header_bmp_two(t_info *info, unsigned char *bmp)
{
	int im_size;
	int pad;

	info->r_width = info->start_w;
	info->r_height = info->start_h;
	pad = info->r_width % 4;
	im_size = ((info->r_width * 3) + pad) * info->r_height;
	bmp[18] = (unsigned char)(info->r_width);
	bmp[19] = (unsigned char)(info->r_width >> 8);
	bmp[20] = (unsigned char)(info->r_width >> 16);
	bmp[21] = (unsigned char)(info->r_width >> 24);
	bmp[22] = (unsigned char)(info->r_height);
	bmp[23] = (unsigned char)(info->r_height >> 8);
	bmp[24] = (unsigned char)(info->r_height >> 16);
	bmp[25] = (unsigned char)(info->r_height >> 24);
	bmp[26] = 1;
	bmp[28] = 24;
	bmp[34] = (unsigned char)(im_size);
	bmp[35] = (unsigned char)(im_size >> 8);
	bmp[36] = (unsigned char)(im_size >> 16);
	bmp[37] = (unsigned char)(im_size >> 24);
}

static void		pixel_bmp(int fd, t_info *info)
{
	int		y;
	int		x;
	int		pad;
	int		color;
	char	*p;

	p = NULL;
	y = info->r_height - 1;
	pad = info->r_width % 4;
	while (y >= 0)
	{
		x = 0;
		while (x < info->r_width)
		{
			color = *(unsigned int *)((char*)info->img.data +
					(y * info->img.size_l) + x * (info->img.bpp / 8));
			write(fd, &color, 3);
			x++;
		}
		write(fd, &p, pad);
		y--;
	}
}

static void		record_bmp(int fd, t_info *info)
{
	unsigned char *bmp;

	bmp = ft_calloc(54, sizeof(char));
	header_bmp_one(info, bmp);
	header_bmp_two(info, bmp);
	info->r_width = info->start_w;
	write(fd, bmp, 54);
	main_buf(info);
	main_texture(info);
	load_texture(info);
	info->win = mlx_new_window(info->mlx, info->r_width,
												info->r_height, "MCARRY");
	info->img.img = mlx_new_image(info->mlx, info->r_width, info->r_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
										&info->img.size_l, &info->img.endian);
	main_loop(info);
	pixel_bmp(fd, info);
}

void			pars_save(char *argv, t_info *info)
{
	int sixsymbols;
	int fd;

	sixsymbols = ft_strlen(argv);
	if (sixsymbols != 6)
		error_exit("ОШИБКА\n");
	else
	{
		if ((ft_strnstr(argv, "--save", 6)))
		{
			fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
			record_bmp(fd, info);
			printf("файл BMP создан\n");
			exit(EXIT_SUCCESS);
		}
	}
}
