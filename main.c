/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "runner.h"
#include "my.h"

int usage(const char *bin)
{
    my_printf("My runner:\n\n\tUsage: %s [path_to_map]. \
If no map are specified, the default one is loaded.\n\n\
Moves:\n\tQ or D to move to the left or right\n\t\
SPACE to jump (you can release the jump before the end to jump lower)\n", bin);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (start_game("prefabs/game.gcprefab"));
    if (argc != 2 || !my_strcmp(argv[1], "-h"))
        return (usage(argv[0]));
    return (start_game(argv[1]));
}