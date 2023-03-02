################################################################################
#									 CONFIG								   #
################################################################################

NAME		:= 	webserv
CC			:= 	c++
FLAGS		:= 	-Wall -Wextra -Werror -Wpedantic -g --std=c++98
 
################################################################################
#								 PROGRAM'S SRCS							   #
################################################################################

SRCS		:=	srcs/init.cpp	\
				srcs/serv.cpp
HEADERS 	:= 	includes/header.hpp
OBJS		:= 	${SRCS:.cpp=.o}

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

################################################################################
#								  Makefile  objs							  #
################################################################################

CLR_RMV		:= 	\033[0m
RED			:= 	\033[1;31m
GREEN		:= 	\033[1;32m
YELLOW		:= 	\033[1;33m
BLUE		:= 	\033[1;34m
CYAN		:= 	\033[1;36m
RM			:= 	rm -rf

all:		${OBJS} ${S_HEADERS} Makefile
			@ echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@ if [ ! -d "objs" ]; then mkdir objs; fi
			@ mv srcs/*.o objs/
			@ echo "$(GREEN)$(NAME) created ✔️${CLR_RMV}"

clean:
			@ if [ -d "objs" ]; then ${RM} objs; fi
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
