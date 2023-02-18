# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 23:30:52 by anguinau          #+#    #+#              #
#    Updated: 2022/03/03 17:54:28 by anguinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS =	main.c \
		utils.c \
		ft_split.c \
		ft_strjoin.c \
		get_cmd.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
RM		= rm -f

.c.o			:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

all				:	${NAME}

${NAME}			:	${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean			:
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re