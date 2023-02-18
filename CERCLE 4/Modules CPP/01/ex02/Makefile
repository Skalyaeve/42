NAME			=	HiThisIsBrain
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 
CC				=	c++
RM				=	rm -rf

SRCS			=	main.cpp
OBJS			=	$(SRCS:.cpp=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS) 
					${CC} $(CFLAGS) ${OBJS} -o ${NAME}

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.cpp
					$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					@$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all bonus clean fclean re