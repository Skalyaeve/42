# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 00:39:01 by anguinau          #+#    #+#              #
#    Updated: 2022/02/12 19:23:28 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_memset.c		\
		ft_swap.c			\
		ft_split.c			\
		ft_substr.c			\
		ft_strlcpy.c		\
		ft_strjoin.c		\
		ft_strdup.c			\
		ft_strlen.c			\
		ft_strcut.c			\
		ft_strchr.c			\
		malloc_things.c		\
		ft_long_long_atoi.c	\
		ft_atoi.c			\
		ft_itoa.c			\
		ft_putstr_fd.c		\
		ft_putnbr_fd.c		\
		ft_isprint.c		\
		ft_isascii.c		\
		return_int.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isdigit.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strncmp.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

${NAME}	:	${OBJS}
			ar rcs ${NAME} ${OBJS}

.c.o	:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all		:	${NAME}
			
so		:
			$(CC) -c -fPIC $(CFLAGS) $(SRCS)
			gcc -shared -o libft.so $(OBJS)

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME} libft.so

re		:	fclean all
			${RM} ${OBJS}

.PHONY	:	all bonus clean fclean re
