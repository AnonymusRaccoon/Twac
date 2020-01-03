/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** gravity_system
*/


#include "entity.h"
#include "system.h"
#include "texture.h"
#include "vector2.h"
#include "utility.h"
#include "components/movable_component.h"
#include "components/gravity_component.h"
#include "components/collision_component.h"
#include <stddef.h>

void gravity_update_entity(gc_engine *engine, void *system, \
gc_entity *entity, float dtime)
{
    struct gravity_component *grav = GETCMP(gravity_component);
    struct movable_component *mov = GETCMP(movable_component);
    struct collision_component *col = GETCMP(collision_component);

    if (mov->acceleration.y > -grav->gravity_speed) {
        if (mov->acceleration.y > 0)
            mov->acceleration.y -= grav->gravity_speed;
        else
            mov->acceleration.y = -grav->gravity_speed;
    }
    if (mov->acceleration.y < 0 && col->distance_down == 0) {
        mov->acceleration.y = 0;
        mov->velocity.y = 0;
    }
    (void)system;
    (void)dtime;
    (void)engine;
}

void gravity_destroy(void *system)
{
    (void)system;
}

const gc_system gravity_system = {
    name: "GravitySystem",
    component_name: "gravity_component",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &gravity_update_entity,
    destroy: &gravity_destroy
};