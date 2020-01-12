/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** live_component
*/

#include "xml.h"
#include "component.h"
#include "components/live_component.h"
#include "components/collision_component.h"
#include "components/transform_component.h"
#include "components/win_component.h"
#include "components/controllable_component.h"
#include "components/timer_component.h"
#include "utility.h"
#include "prefab.h"
#include <stdlib.h>

void reset_timer(gc_scene *scene)
{
    gc_entity *entity = scene->get_entity(scene, 50);
    struct timer_component *timer;

    if (!entity)
        return;
    timer = GETCMP(timer_component);
    timer->time_left = timer->default_value;
}

void live_collide(gc_engine *engine, gc_entity *entity, int id)
{
    struct live_component *cmp = GETCMP(live_component);
    struct transform_component *trans = GETCMP(transform_component);
    struct controllable_component *con = GETCMP(controllable_component);

    if (GETCOLCMP(win_component)) {
        prefab_load(engine, "prefabs/winscreen.gcprefab");
        entity->remove_component(engine->scene, entity, "keyboard_controller");
        con->jumping = false;
        con->moving_left = false;
        con->moving_right = false;
    }
    else if (GETCOLCMP(kill_component) || id == -1) {
        cmp->live--;
        if (cmp->live == 0) {
            engine->should_close = true;
        } else {
            trans->position = cmp->spawn_position;
            reset_timer(engine->scene);
        }
    }
}

static void ctr(void *component, va_list args)
{
    struct live_component *cmp = (struct live_component *)component;
    gc_entity *entity = va_arg(args, gc_entity *);
    struct collision_component *col;
    struct transform_component *trans;

    if (entity) {
        col = GETCMP(collision_component);
        trans = GETCMP(transform_component);
        if (col)
            add_on_collide(col, &live_collide);
        if (trans)
            cmp->spawn_position = trans->position;
    }
    cmp->live = va_arg(args, int);
}

static void fdctr(gc_entity *entity, gc_scene *scene, void *component, node *n)
{
    struct live_component *cmp = (struct live_component *)component;
    struct transform_component *trans = GETCMP(transform_component);
    struct collision_component *col = GETCMP(collision_component);

    cmp->live = xml_getintprop(n, "count");
    if (!trans)
        return ((void)my_printf("Transform not yet setup, you should place the \
live component after the collision component.\n"));
    if (!col)
        return ((void)my_printf("Collision not yet setup, you should place the \
live component after the collision component.\n"));
    cmp->spawn_position = trans->position;
    add_on_collide(col, &live_collide);
    (void)scene;
}

static void dtr(void *component)
{
    (void)component;
}

static char *serialize(void *component)
{
    (void)component;
    return (NULL);
}

const struct live_component live_component = {
    base: {
        name: "live_component",
        size: sizeof(struct live_component),
        dependencies: (char *[]){
            "transform_component",
            "collision_component",
            NULL
        },
        ctr: &ctr,
        fdctr: &fdctr,
        dtr: &dtr,
        serialize: &serialize,
        destroy: &component_destroy
    },
    live: 3
};