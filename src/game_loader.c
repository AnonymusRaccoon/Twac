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
    gc_engine *engine = engine_create("Runner");
    gc_scene *scene;

    if (!engine)
        return (ERROR);
    scene = create_game_scene(engine);
    if (!scene)
        return (ERROR);
    engine->change_scene(engine, scene);
    while (engine->is_open(engine)) {
        engine->game_loop(engine);
    }
    return (0);
}