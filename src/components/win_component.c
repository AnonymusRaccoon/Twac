/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** win_component
*/

#include "component.h"
#include "components/win_component.h"
#include "utility.h"
#include <stdlib.h>

static char *serialize(void *component)
{
    (void)component;
    return (NULL);
}

const struct gc_component win_component = {
    name: "win_component",
    size: sizeof(struct gc_component),
    dependencies: (char *[]){
        "collision_component",
        "transform_component",
        NULL
    },
    ctr: NULL,
    fdctr: NULL,
    dtr: NULL,
    serialize: &serialize,
    destroy: &component_destroy
};