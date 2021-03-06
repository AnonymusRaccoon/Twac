/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** walk_action
*/

#include "entity.h"
#include "system.h"
#include "vector2.h"
#include "component.h"
#include "components/collision_component.h"
#include "components/movable_component.h"
#include "components/controllable_component.h"
#include "components/jump_action.h"
#include "components/renderer.h"
#include "utility.h"
#include <stddef.h>

static void update_entity(gc_engine *engine __attribute__((unused)), \
void *system __attribute__((unused)), gc_entity *entity, \
float dtime __attribute__((unused)))
{
    struct collision_component *col = GETCMP(collision_component);
    struct controllable_component *con = GETCMP(controllable_component);
    struct movable_component *mov = GETCMP(movable_component);
    struct jump_action *jump = GETCMP(jump_action);
    struct renderer *rend = GETCMP(renderer);

    if (col->distance_down == 0 && con->jumping) {
        mov->acceleration.y += jump->acceleration;
        jump->contered = false;
        jump->step = jump->step_count;
    } else if (!jump->contered && mov->velocity.y > 0 && !con->jumping) {
        jump->contered = true;
        jump->step = 0;
    }
    if (jump->step > 0) {
        mov->acceleration.y += jump->acceleration;
        jump->step--;
    }
    if (rend && rend->type == GC_ANIMREND && col->distance_down != 0)
        rend_set_anim(rend, "jump");
}

static void destroy(void *system)
{
    (void)system;
}

const gc_system jump_system = {
    name: "jump_system",
    component_name: "jump_action",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &update_entity,
    destroy: &destroy
};