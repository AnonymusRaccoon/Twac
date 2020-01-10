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
#include "components/movable_component.h"
#include "components/controllable_component.h"
#include "components/walk_action.h"
#include "components/renderer.h"
#include "utility.h"
#include "sprite.h"
#include <stddef.h>

void walk_update_entity(gc_engine *engine __attribute__((unused)), \
void *system __attribute__((unused)), gc_entity *entity, \
float dtime __attribute__((unused)))
{
    struct controllable_component *con = GETCMP(controllable_component);
    struct movable_component *mov = GETCMP(movable_component);
    struct walk_action *wal = GETCMP(walk_action);
    struct renderer *rend = GETCMP(renderer);

    if (con->moving_left)
        mov->acceleration.x -= wal->acceleration;
    if (con->moving_right)
        mov->acceleration.x += wal->acceleration;
    if (rend) {
        if (mov->velocity.x < 0)
            SET_SIGN(((gc_animholder *)rend->data)->sprite->scale.x, -1);
        else
            SET_SIGN(((gc_animholder *)rend->data)->sprite->scale.x, 1);
        if (rend->type != GC_ANIMREND)
            return;
        if (con->moving_left != con->moving_right)
            rend_set_anim(rend, "walk");
        else if (-wal->idle <= mov->velocity.x && mov->velocity.x <= wal->idle)
            rend_set_anim(rend, "none");
    }
}

void walk_destroy(void *system)
{
    (void)system;
}

const gc_system walk_system = {
    name: "walk_system",
    component_name: "walk_action",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &walk_update_entity,
    destroy: &walk_destroy
};