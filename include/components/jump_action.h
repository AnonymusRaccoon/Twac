/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** walk_action
*/

#pragma once

#include "component.h"
#include <stdbool.h>

struct jump_action
{
    gc_component base;
    int acceleration;
    int counterforce;
    bool contered;
    int step;
    int step_count;
};

extern const struct jump_action jump_action;