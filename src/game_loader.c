/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_loader
*/

#include "engine.h"
#include "runner.h"
#include "prefab.h"

int register_customcmps(gc_engine *engine)
{
    (void)engine;
    return (0);
}

int create_game_scene(gc_engine *engine, const char *map)
{
    gc_scene *scene;

    register_customcmps(engine);
    scene = scene_create(engine, map);
    if (!scene)
        return (-1);
    engine->change_scene(engine, scene);
    if (prefab_load(engine, "prefabs/player.gcprefab") < 0)
        return (-1);
    return (0);
}

int start_game(const char *map)
{
    gc_engine *engine = engine_create();
    sfClock *clock = sfClock_create();

    if (!engine || engine_use_sfml(engine, "Twac", 60) < 0)
        return (ERROR);
    if (create_game_scene(engine, map) < 0)
        return (ERROR);
    while (engine->is_open(engine)) {
        engine->game_loop(engine, sfTime_asSeconds(sfClock_restart(clock)));
    }
    engine->destroy(engine);
    sfClock_destroy(clock);
    return (0);
}