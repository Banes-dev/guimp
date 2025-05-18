ifeq ($(OS),Windows_NT)
	SDL_PATH = ./libui/SDL_BUILD_Windows
	LDFLAGS = -L$(SDL_PATH)/lib -lmingw32 -lSDL2main -lSDL2 -mwindows
else
	SDL_PATH = ./libui/SDL_BUILD
	LDFLAGS = -L$(SDL_PATH)/lib -lSDL2 -lm
endif
## -lSDL2_image -lSDL2_ttf

COMP = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++11 -I./libui/src -I$(SDL_PATH)/include/SDL2

# Normal
NAME = guimp
FUNC = $(wildcard src/*.cpp)
OBJS = $(FUNC:.cpp=.o)
LIBUI = ./libui/libui.a


# Compil
all: 	$(NAME)

$(NAME): $(LIBUI) $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) $(LIBUI) $(LDFLAGS) -o $(NAME)

$(LIBUI):
	make -C ./libui

%.o: %.cpp
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libui clean

fclean:	clean
	rm -f $(NAME)
	make -C ./libui fclean

re:	fclean all

.PHONY: all clean fclean re