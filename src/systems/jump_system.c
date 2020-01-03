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

    if (con->jumping)
        printf("Acceleartion: %4.0f, Velocity: %4.0f Distance down: %d\n", mov->acceleration.y, mov->velocity.y, col->distance_down);
    if (col->distance_down == 0 && mov->acceleration.y < jump->max_acceleration)
        mov->acceleration.y += con->jumping * jump->acceleration;
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