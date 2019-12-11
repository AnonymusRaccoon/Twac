/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_scene
*/

#include "scene.h"
#include "prefab.h"
#include <stddef.h>

static const char *textures[] = {
    "assets/sprites/bck_layer1.png",
    "assets/sprites/bck_layer2.png",
    "assets/sprites/bck_layer3.png",
    "assets/sprites/bck_layer4.png",
    "assets/sprites/grass.png",
    NULL
};

int create_game_scene(gc_engine *engine)
{
    gc_scene *scene = scene_create(textures);

    if (!scene)
        return (-1);
    engine->change_scene(engine, scene);
    if (prefab_load(engine, "prefabs/game.gcprefab") < 0)
        return (-1);
    if (prefab_load(engine, "prefabs/player.gcprefab") < 0)
        return (-1);
    return (0);
}