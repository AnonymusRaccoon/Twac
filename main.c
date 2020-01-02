/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "runner.h"
#include "my.h"

int usage(void)
{
    return (ERROR);
}

int main(int argc, char **argv)
{
    if (argc != 2 || !my_strcmp(argv[1], "-h"))
        return (usage());
    return (start_game(argv[1]));
}