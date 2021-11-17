CC 			= 	gcc
NAME_SERVER	=	server
NAME_CLIENT	=	client
INCLUDES	=	includes/minitalk.h
SRCS_CLIENT	=	srcs/client.c srcs/ft_atoi_ultimate.c
SRCS_SERVER	=	srcs/server.c

OBJS_CLIENT =	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

all : $(NAME_SERVER) $(NAME_CLIENT)

######################################### SERVER #########################################
$(NAME_SERVER): $(OBJS_SERVER) $(INCLUDES)
	$(CC) ${CFLAGS} $(OBJS_SERVER) -o $(NAME_SERVER)

######################################### CLIENT #########################################
$(NAME_CLIENT): $(OBJS_CLIENT) $(INCLUDES)
	$(CC) ${CFLAGS} $(OBJS_CLIENT) -o $(NAME_CLIENT)

##########################################################################################

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)

re:
	make fclean
	make all

.PHONY: all clean fclean re
