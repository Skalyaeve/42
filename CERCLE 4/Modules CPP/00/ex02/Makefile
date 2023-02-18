NAME			=	Account
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 
CC				=	c++
RM				=	rm -rf

HEADERS			=	$(shell find . -type f -name "*.hpp")
SRCS			=	$(shell find . -type f -name "*.cpp")
SRCS_COUNT		=	$(shell find $(SRCSDIR) -type f -name "*.cpp" | wc -l)
OBJS			=	$(SRCS:.cpp=.o)

all				:	$(NAME)

ifeq ($(SRCS_COUNT), 2)
$(NAME)			:	$(OBJS) 
					${CC} $(CFLAGS) ${OBJS} -o ${NAME}
else
$(NAME)			:
					@echo "Srcs corrupted, abording."
endif

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.cpp $(HEADERS)
					$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					@$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all bonus clean fclean re