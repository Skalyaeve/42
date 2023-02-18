# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 20:43:33 by anguinau          #+#    #+#              #
#    Updated: 2020/11/25 18:27:00 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c		\
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c		\
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c	\
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c	\
	  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c		\
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c		\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\

B_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstclear.c	\
	  ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c		\

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

.c.o		:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all		:	${NAME}

bonus		:	${NAME} ${B_OBJS}
			ar rcs ${NAME} ${OBJS} ${B_OBJS}

${NAME}		:	${OBJS}
			ar rcs ${NAME} ${OBJS}

so		:
			$(CC) -c -fPIC $(CFLAGS) $(SRCS) ${B_SRCS}
			gcc -shared -o libft.so $(OBJS) ${B_OBJS}
clean		:
			${RM} ${OBJS} ${B_OBJS}

fclean		:	clean
			${RM} ${NAME} libft.so

re		:	fclean all

.PHONY		:	all bonus clean fclean re
