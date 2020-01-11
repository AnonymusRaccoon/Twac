/*
** EPITECH PROJECT, 2019
** Gamacon
** File description:
** gravity_component
*/

#pragma once

#include "component.h"

struct timer_component
{
    gc_component base;
    float time_left;
    int default_value;
};

extern const struct timer_component timer_component;