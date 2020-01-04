/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** walk_action
*/

#include "entity.h"
#include "system.h"
#include "texture.h"
#include "vector2.h"
#include "component.h"
#include "components/movable_component.h"
#include "components/controllable_component.h"
#include "components/walk_action.h"
#include "utility.h"
#include <stddef.h>

void walk_update_entity(gc_engine *engine, void *system, \
gc_entity *entity, float dtime)
{
    struct controllable_component *con = GETCMP(controllable_component);
    struct movable_component *mov = GETCMP(movable_component);
    struct walk_action *walk = GETCMP(walk_action);
    gc_vector2 *acc = &mov->acceleration;

    if (con->moving_left)
        acc->x -= walk->acceleration;
    if (con->moving_right)
        acc->x += walk->acceleration;
    (void)system;
    (void)dtime;
    (void)engine;
}

void walk_destroy(void *system)
{
    (void)system;
}

const gc_system walk_system = {
    name: "WalkSystem",
    component_name: "walk_action",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &walk_update_entity,
    destroy: &walk_destroy
};