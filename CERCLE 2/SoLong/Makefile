# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 01:48:21 by anguinau          #+#    #+#              #
#    Updated: 2022/02/07 16:20:40 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
SRCS		= main.c \
			parsing.c \
			check_map_infos.c \
			create_map_tab.c \
			mlx_start.c \
			upload_sprites.c \
			reversed_char.c \
			key_hook.c \
			loop_hook.c \
			loop_hook_bis.c \
			draw.c \
			free_map_infos.c \
			assign_sprites.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
INCLUDES	= mlx_linux/ -lmlx -lXext -lX11
RM			= rm -f

.c.o			:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

all				:	${NAME}

make_mlx		:
					cd mlx_linux && make

clean_mlx		:
					cd mlx_linux && make clean


${NAME}			:	make_mlx ${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${INCLUDES} 

clean			:
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
