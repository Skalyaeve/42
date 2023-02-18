# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 18:15:19 by anguinau          #+#    #+#              #
#    Updated: 2021/02/13 09:29:30 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c utils.c utils_bis.c utils_bis_bis.c last_utils.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

.c.o		:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all		:	${NAME}

${NAME}		:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean		:
			${RM} ${OBJS}

fclean		:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY		:	all clean fclean re
