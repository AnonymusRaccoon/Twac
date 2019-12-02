/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_loader
*/

#include "engine.h"

int start_game()
{
    gcEngine *engine = create_engine("Runner");

    while (engine->is_open(engine)) {
        engine->game_loop(engine);
    }
    return (0);
}