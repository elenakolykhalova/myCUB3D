/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_load_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:41:59 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 04:22:53 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
														&img->img_height)))
	{
		printf("ТЕКСТУРА НЕ НАЙДЕНА\n");
		exit(EXIT_SUCCESS);
	}
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
															&img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->so, &img);
	load_image(info, info->texture[1], info->no, &img);
	load_image(info, info->texture[2], info->ea, &img);
	load_image(info, info->texture[3], info->we, &img);
	load_image(info, info->texture[4], info->s, &img);
}
