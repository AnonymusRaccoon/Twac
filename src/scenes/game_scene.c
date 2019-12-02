/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_scene
*/

#include "scene.h"
#include <stddef.h>

static const char *textures[] = {"assets/sprites/bck_layer1.png", \
"assets/sprites/bck_layer2.png", "assets/sprites/bck_layer3.png", \
"assets/sprites/bck_layer4.png", NULL};

gc_scene *create_game_scene(void)
{
    gc_scene *scene = scene_create(textures);

    return (scene);
}