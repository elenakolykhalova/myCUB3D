/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:04:17 by mcarry            #+#    #+#             */
/*   Updated: 2021/04/09 03:18:44 by mcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13

# define K_ARROW_L 124
# define K_ARROW_R 123
# define K_ESC 53

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_check
{
	int			flag_r;
	int			flag_no;
	int			flag_so;
	int			flag_we;
	int			flag_ea;
	int			flag_s;
	int			flag_f;
	int			flag_c;
	int			flag_map_st;
}				t_check;

typedef struct	s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;

	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_l;
	int			key_r;
	int			key_esc;

	t_img		img;

	char		**map;
	double		**mapsp;
	int			map_line;

	int			count_plr;
	int			count_sp;
	int			sp_num;

	t_list		*list_map;

	int			r_width;
	int			r_height;
	int			start_w;
	int			start_h;

	t_check		set;

	int			r_check_w;
	int			r_check_h;

	int			**buf;
	double		*z_buffer;
	int			**texture;
	double		move_speed;
	double		rot_speed;

	void		*so;
	void		*no;
	void		*we;
	void		*ea;
	void		*s;

	int			f_r;
	int			f_g;
	int			f_b;
	int			f_rgb;
	int			c_r;
	int			c_g;
	int			c_b;
	int			c_rgb;

	int			system_width;
	int			system_height;
	double		oldplane_x;
	double		olddir_x;

	int			y;
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			color;

	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x_s;
	int			d;
	int			tex_y_s;
}				t_info;

char			**pars_map(t_info *info, int size);
void			init_plr(t_info *info, int i, int j);
void			count_plr(t_info *info);

void			pars_save(char *argv, t_info *info);
int				main_loop(t_info *info);

void			load_texture(t_info *info);

void			calc(t_info *info);
void			draw(t_info *info);

char			**ft_copy_map(t_info *info, int size);
void			check_cub(char *argv);
int				flood_fill(char **map, int x, int y);

void			pars_options(char *line, t_info *info, int i);
void			init_sprites(t_info *info, int i, int j);
int				create_trgb(int t, int r, int g, int b);

void			free_item(char **s);
void			cleaning(t_info *info);
void			key_update(t_info *info);
int				key_press(int key, t_info *info);
int				key_release(int key, t_info *info);
int				key_close_programm(void);
void			up_down(t_info *info);
void			left_right(t_info *info);
void			rotation_key_r(t_info *info);
void			rotation_key_l(t_info *info);

int				error_exit(char *error);
int				resolution(t_info *info, char **tmp);
void			texture(char *line, t_info *info, char **tmp);
void			check_color(char *line, t_info *info, char **tmp, int i);
void			check_map(char *line, t_info *info);
int				check_flags(t_info *info);
void			check_map_error(char *line, t_info *info);
void			sort_sprites(int *order, double *dist, int amount);
void			window(t_info info);
void			main_texture(t_info *info);
void			main_buf(t_info *info);
void			read_file(char **argv, t_info *info);
void			calc_sprites(t_info *info);
void			calc_draw_texture(t_info *info);
void			calc_draw_floor_ceiling_tex(t_info *info);
void			perform_dda(t_info *info);
void			step_x_y(t_info *info);
void			perp_wall_dist_draw_start_end(t_info *info);
void			sprite_screen(t_info *info);
void			calc_height_width_sprite(t_info *info);
void			transform_sprite(t_info *info);
void			for_every_pixel(t_info *info);
void			function(t_info *info);

#endif
