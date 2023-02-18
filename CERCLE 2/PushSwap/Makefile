# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 15:53:25 by anguinau          #+#    #+#              #
#    Updated: 2022/03/03 08:53:36 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= main.c								\
		utils.c									\
		manage_stacks.c							\
		manage_stacks_bis.c						\
		push_swap.c								\
		rotate.c								\
		gt_n_index_method/index_method.c		\
		gt_n_index_method/index_method_bis.c	\
		gt_n_index_method/index_method_ter.c	\
		gt_n_index_method/gt_method.c			\
		gt_n_index_method/gt_method_bis.c		\
		gt_n_index_method/gt_method_ter.c		\
		gt_n_index_method/gt_method_quat.c		\
		gt_n_index_method/gt_method_quint.c		\
		gt_n_index_method/gt_method_six.c		\
		gt_n_index_method/check_a_stacks.c		\
		gt_n_index_method/check_b_stacks.c		
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
RM		= rm -f
LIB		= Libft/libft.a

.c.o			:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

all				:	${NAME}
					
make_libft		:
					cd Libft && make

clean_libft		:
					cd Libft && make clean

fclean_libft	:
					cd Libft && make fclean

${NAME}			:	make_libft ${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L. ${LIB}

clean			:	clean_libft
					${RM} ${OBJS}

fclean			:	clean fclean_libft
					${RM} ${NAME}

re				:	fclean all
					make clean

.PHONY			:	all clean fclean re
