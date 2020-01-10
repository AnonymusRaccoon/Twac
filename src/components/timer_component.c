/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** timer_component
*/

#include "component.h"
#include "components/timer_component.h"
#include "utility.h"
#include <stdlib.h>

static void ctr(void *component, va_list args)
{
    struct timer_component *cmp = (struct timer_component *)component;

    cmp->time_left = va_arg(args, double);
}

static void fdctr(gc_entity *entity, gc_scene *scene, void *component, node *n)
{
    struct timer_component *cmp = (struct timer_component *)component;

    cmp->time_left = xml_getintprop(n, "time");
    (void)entity;
    (void)scene;
}

static char *serialize(void *component)
{
    (void)component;
    return (NULL);
}

const struct timer_component timer_component = {
    base: {
        name: "timer_component",
        size: sizeof(struct timer_component),
        dependencies: (char *[]){
            "renderer",
            NULL
        },
        ctr: &ctr,
        fdctr: &fdctr,
        dtr: NULL,
        serialize: &serialize,
        destroy: &component_destroy
    }
};