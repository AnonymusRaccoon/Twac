##
## EPITECH PROJECT, 2019
## MUL_my_runner_2019
## File description:
## Makefile
##

SRC = main.c \
	src/game_loader.c \
	src/scenes/game_scene.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = -I ./include -I lib/gamacon/include -I lib/gamacon/lib/xmlparser/include

CFLAGS = $(INCLUDE) -Wall -Wshadow -Wextra

LDFLAGS = -L lib/gamacon -L lib/my -L lib/xmlparser \
-lgamacon -lxmlparser -lmy -lcsfml-system -lcsfml-graphics -lcsfml-window

NAME = my_runner

CC = gcc

all: build

build: $(OBJ)
	$(MAKE) -C lib/gamacon
	$(MAKE) -C lib/my
	$(MAKE) -C lib/xmlparser
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) -C lib/gamacon clean
	$(MAKE) -C lib/my clean
	$(MAKE) -C lib/xmlparser clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

ffclean: fclean
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/gamacon fclean
	$(MAKE) -C lib/xmlparser fclean

re: fclean all

dbg: CFLAGS += -g
dbg: clean $(OBJ)
	$(MAKE) -C lib/gamacon dbg
	$(MAKE) -C lib/my
	$(MAKE) -C lib/xmlparser dbg
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

.PHONY: all build clean fclean ffclean