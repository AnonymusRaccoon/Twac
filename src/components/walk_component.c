/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** walk_action
*/

#include "xml.h"
#include "component.h"
#include "components/controllable_component.h"
#include "components/walk_action.h"
#include "utility.h"
#include <stdlib.h>

static void ctr(void *component, va_list args)
{
    struct walk_action *cmp = (struct walk_action *)component;

    cmp->acceleration = va_arg(args, int);
    cmp->idle = va_arg(args, int);
}

static void fdctr(gc_entity *entity, gc_scene *scene, void *component, node *n)
{
    struct walk_action *cmp = (struct walk_action *)component;

    cmp->acceleration = xml_getintprop(n, "acceleration");
    cmp->idle = xml_getintprop(n, "idle_trigger");
    (void)scene;
    (void)entity;
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

const struct walk_action walk_action = {
    base: {
        name: "walk_action",
        size: sizeof(struct walk_action),
        dependencies: (char *[]){
            "controllable_component",
            "movable_component",
            "transform_component",
            NULL
        },
        ctr: &ctr,
        fdctr: &fdctr,
        dtr: &dtr,
        serialize: &serialize,
        destroy: &component_destroy
    },
    acceleration: 0
};