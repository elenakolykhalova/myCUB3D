# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarry <mcarry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 03:36:09 by mcarry            #+#    #+#              #
#    Updated: 2021/04/09 03:36:13 by mcarry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= bmp_pars.c key_control.c init_player.c raycast_load_image.c \
			  pars_options.c utilities.c pars_error.c key_update.c \
			  pars_resolution.c pars_texture.c pars_color.c\
			  pars_map.c main.c raycast_utilities.c raycast_calc.c \
			  utilities_main.c raycast_calc_sprite.c raycast_calc_util.c \
			  raycast_calc_sprite_util.c \
			  ${GNL_DIR}/get_next_line.c ${GNL_DIR}/get_next_line_utils.c

HEADERS		= cub3d.h key_macos.h

OBJS		= ${SRCS:.c=.o}

NAME		= cub3D

LIBFT_DIR	= libft/
MLX_DIR		= minilibx/
GNL_DIR		= get_next_line/

LIBFT		= libft.a
MLX			= libmlx.a

INCLUDES	= -I${LIBFT_DIR} -I${MLX_DIR} -I${GNL_DIR}

CC			= gcc

RM			= rm -f

CFLAGS		= -g  -Wall -Wextra -Werror
MLXFLAGS	= -framework OpenGL -framework Appkit

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${LIBFT_DIR}${LIBFT} ${MLX_DIR}${MLX} ${OBJS}
			${CC} ${OBJS} ${INCLUDES} -L${LIBFT_DIR} -lft -L${MLX_DIR} -lmlx ${MLXFLAGS} -o ${NAME}

${LIBFT_DIR}${LIBFT}: ${LIBFT_DIR}
			${MAKE} -C ${LIBFT_DIR} bonus

${MLX_DIR}${MLX}:		${MLX_DIR}
			${MAKE} -C ${MLX_DIR} all

bonus:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} -C ${LIBFT_DIR} clean
			${MAKE} -C ${MLX_DIR} clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C ${LIBFT_DIR} fclean
#			cd libft && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re
