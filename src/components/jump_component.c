/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** walk_action
*/

#include "xml.h"
#include "component.h"
#include "components/controllable_component.h"
#include "components/jump_action.h"
#include "utility.h"
#include <stdlib.h>

static void ctr(void *component, va_list args)
{
    struct jump_action *cmp = (struct jump_action *)component;

    cmp->acceleration = va_arg(args, int);
    cmp->counterforce = va_arg(args, int);
    cmp->step_count = va_arg(args, int);
    cmp->step = 0;
    cmp->contered = false;
}

static void fdctr(gc_entity *entity, gc_scene *scene, void *component, node *n)
{
    struct jump_action *cmp = (struct jump_action *)component;

    cmp->acceleration = xml_getintprop(n, "acceleration");
    cmp->counterforce = xml_getintprop(n, "counterforce");
    cmp->step_count = xml_getintprop(n, "step_count");
    cmp->step = 0;
    cmp->contered = false;
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

const struct jump_action jump_action = {
    base: {
        name: "jump_action",
        size: sizeof(struct jump_action),
        dependencies: (char *[]){
            "controllable_component",
            "collision_component",
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