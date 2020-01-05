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
#include "components/collision_component.h"
#include "components/movable_component.h"
#include "components/controllable_component.h"
#include "components/jump_action.h"
#include "utility.h"
#include <stddef.h>

static void update_entity(gc_engine *engine, void *system,
gc_entity *entity, float dtime)
{
    struct collision_component *col = GETCMP(collision_component);
    struct controllable_component *con = GETCMP(controllable_component);
    struct movable_component *mov = GETCMP(movable_component);
    struct jump_action *jump = GETCMP(jump_action);

    if (col->distance_down == 0) {
        mov->acceleration.y += con->jumping * jump->acceleration;
        jump->contered = false;
    } else if (!jump->contered && mov->acceleration.y > 0 && !con->jumping) {
        jump->contered = true;
        if (mov->acceleration.y > 0)
            mov->acceleration.y -= MIN(jump->counterforce, mov->acceleration.y);
    }
    (void)system;
    (void)dtime;
    (void)engine;
}

static void destroy(void *system)
{
    (void)system;
}

const gc_system jump_system = {
    name: "JumpSystem",
    component_name: "jump_action",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &update_entity,
    destroy: &destroy
};