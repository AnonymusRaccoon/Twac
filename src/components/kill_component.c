/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** kill_component
*/


#include "component.h"
#include "components/kill_component.h"
#include "utility.h"
#include <stdlib.h>

static char *serialize(void *component)
{
    (void)component;
    return (NULL);
}

const struct kill_component kill_component = {
    base: {
        name: "kill_component",
        size: sizeof(struct kill_component),
        dependencies: (char *[]){
            "movable_component",
            "transform_component",
            NULL
        },
        ctr: NULL,
        fdctr: NULL,
        dtr: NULL,
        serialize: &serialize,
        destroy: &component_destroy
    }
};