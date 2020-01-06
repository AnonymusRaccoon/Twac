/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** gravity_component
*/

#include "xml.h"
#include "component.h"
#include "components/gravity_component.h"
#include "utility.h"
#include <stdlib.h>

static void ctr(void *component, va_list args)
{
    struct gravity_component *cmp = (struct gravity_component *)component;

    cmp->gravity_speed = va_arg(args, int);
}

static void fdctr(gc_entity *entity, gc_scene *scene, void *component, node *n)
{
    struct gravity_component *cmp = (struct gravity_component *)component;

    cmp->gravity_speed = xml_getintprop(n, "force");
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

const struct gravity_component gravity_component = {
    base: {
        name: "gravity_component",
        size: sizeof(struct gravity_component),
        dependencies: (char *[]){
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
    gravity_speed: 10
};