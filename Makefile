CC		=	gcc

NAME	=	Pong

SRC		=	src/main.c									\
			src/general.c								\
			src/player.c								\
			src/screen.c								\
			src/client_serveur/src/Client/main.c		\
			src/client_serveur/src/Serveur/main.c		\
			src/client_serveur/src/Serveur/readClient.c	\

RM		=	rm -f

OBJ		=	$(SRC:.c=.o)

EXEC	=	Pong

CFLAGS	=	-Wall -Wextra -Werror	$(shell	sdl2-config	--cflags)

all		:	$(NAME)


$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2

clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:		fclean all

.PHONY	:	all clean fclean re
