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

INCLUDE = -I ./include -I lib/gamacon/include

CFLAGS = $(INCLUDE) -Wall -Wshadow -Wextra

LDFLAGS = -L lib/gamacon -lgamacon -L lib/my -lmy -lcsfml-system -lcsfml-graphics

NAME = my_runner

CC = gcc

all: build

build: $(OBJ)
	$(MAKE) -C lib/gamacon
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) -C lib/gamacon clean
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

ffclean: fclean
	$(MAKE) -C lib/my fclean
	$(MAKE) -C lib/gamacon fclean

re: fclean all

dbg: CFLAGS += -g
dbg: clean $(OBJ)
	$(MAKE) -C lib/gamacon dbg
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

.PHONY: all build clean fclean ffclean