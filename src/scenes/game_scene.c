/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_scene
*/

#include "scene.h"
#include "prefab.h"
#include <stddef.h>

static const char *textures[] = {"assets/sprites/bck_layer1.png", \
"assets/sprites/bck_layer2.png", "assets/sprites/bck_layer3.png", \
"assets/sprites/bck_layer4.png", NULL};

int create_game_scene(gc_engine *engine)
{
    gc_scene *scene = scene_create(textures);
    gc_entity *entity;

    if (!scene)
        return (-1);
    engine->change_scene(engine, scene);
    entity = prefab_load(engine, "prefabs/player.gcprefab");
    scene->add_entity(scene, entity);
    return (0);
}