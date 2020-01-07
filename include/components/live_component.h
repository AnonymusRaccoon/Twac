/*
** EPITECH PROJECT, 2019
** Gamacon
** File description:
** gravity_component
*/

#pragma once

#include "component.h"

struct live_component
{
    gc_component base;
    int live;
    gc_vector2 spawn_position;
};

extern const struct live_component live_component;