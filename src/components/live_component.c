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
#include "utility.h"
#include <stdlib.h>

static void on_collide(gc_engine *engine, gc_entity *entity, int id)
{
    struct live_component *cmp = GETCMP(live_component);
    struct transform_component *trans = GETCMP(transform_component);

    if (GETCOLCMP(kill_component)) {
        cmp->live--;
        if (cmp->live < 0) {
            engine->should_close = true;
        } else {
            trans->position = cmp->spawn_position;
        }
    }
    if (GETCOLCMP(win_component)) {
        engine->should_close = true;
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
            add_on_collide(col, &on_collide);
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
    add_on_collide(col, &on_collide);
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