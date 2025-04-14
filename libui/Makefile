COMP = c++

SDL_PATH = ./SDL_BUILD
LDFLAGS = -L$(SDL_PATH)/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lm

CFLAGS = -g -Wall -Wextra -Werror -std=c++11 -I$(SDL_PATH)/include/SDL2

# Normal
NAME = libui.a
FUNC = src/Window.cpp
OBJS = $(FUNC:.cpp=.o)


# Compil
all: 	${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.cpp
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re