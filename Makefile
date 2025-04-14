COMP = c++

LIBUI = ./libui/libui.a
SDL_PATH = ./libui/SDL_BUILD
LDFLAGS = -L$(SDL_PATH)/lib -lSDL2 -lm ## -lSDL2_image -lSDL2_ttf
CFLAGS = -g -Wall -Wextra -Werror -std=c++11 -I./libui/src -I$(SDL_PATH)/include/SDL2

# Normal
NAME = guimp
FUNC = src/main.cpp
OBJS = $(FUNC:.cpp=.o)


# Compil
all: 	${NAME}

${NAME}: ${OBJS}
	${COMP} ${CFLAGS} ${OBJS} ${LIBUI} ${LDFLAGS} -o ${NAME}

%.o: %.cpp
	${COMP} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re