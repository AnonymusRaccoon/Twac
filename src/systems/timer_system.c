/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** timer_system
*/

#include "entity.h"
#include "system.h"
#include "vector2.h"
#include "utility.h"
#include "components/timer_component.h"
#include "components/renderer.h"
#include "text.h"
#include <stdlib.h>

static void update_entity(gc_engine *engine, void *system, \
gc_entity *entity, float dtime)
{
    struct renderer *rend = GETCMP(renderer);
    struct timer_component *timer = GETCMP(timer_component);

    if (!rend || rend->type != GC_TXTREND)
        return;
    timer->time_left -= dtime;
    if (((gc_text *)rend->data)->text)
        free(((gc_text *)rend->data)->text);
    ((gc_text *)rend->data)->text = tostr((int)timer->time_left);
    (void)system;
    (void)engine;
}

static void destroy(void *system)
{
    (void)system;
}

const gc_system timer_system = {
    name: "timer_system",
    component_name: "timer_component",
    size: sizeof(gc_system),
    ctr: NULL,
    dtr: NULL,
    check_dependencies: &system_check_dependencies,
    update_entity: &update_entity,
    destroy: &destroy
};