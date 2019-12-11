/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_loader
*/

#include "engine.h"
#include "runner.h"

int start_game(void)
{
    gc_engine *engine = engine_create();
    sfClock *clock = sfClock_create();

    if (!engine || engine_use_sfml(engine, "Runner", 60) < 0)
        return (ERROR);
    if (create_game_scene(engine) < 0)
        return (ERROR);
    while (engine->is_open(engine)) {
        engine->game_loop(engine, sfTime_asSeconds(sfClock_restart(clock)));
    }
    engine->destroy(engine);
    sfClock_destroy(clock);
    return (0);
}