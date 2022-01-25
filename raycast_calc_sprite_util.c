/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calc_sprite_util.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 02:53:01 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 02:59:31 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	function(t_info *info)
{
	transform_sprite(info);
	calc_height_width_sprite(info);
	sprite_screen(info);
}
