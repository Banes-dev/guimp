ifeq ($(OS),Windows_NT)
	IS_WINDOWS := 1
else
	IS_WINDOWS := 0
endif

ifeq ($(IS_WINDOWS),1)
	SDL_PATH = ./libui/SDL_BUILD_Windows
	LDFLAGS = -L$(SDL_PATH)/lib -lmingw32 -lSDL2main -lSDL2 -mwindows
else
	SDL_PATH = ./libui/SDL_BUILD_Windows
	LDFLAGS = -L$(SDL_PATH)/lib -lSDL2 -lm        
endif
## -lSDL2_image -lSDL2_ttf

COMP = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++11 -I./libui/src -I$(SDL_PATH)/include/SDL2
LIBUI = ./libui/libui.a

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