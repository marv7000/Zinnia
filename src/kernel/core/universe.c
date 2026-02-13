#include <zinnia/status.h>
#include <kernel/mem.h>
#include <kernel/spin.h>
#include <kernel/universe.h>

zn_status_t universe_new(struct universe** out) {
    if (!out)
        return ZN_ERR_BAD_ARG;

    struct universe* universe;
    zn_status_t status;
    if ((status = mem_alloc(sizeof(struct universe), 0, (void**)&universe)))
        return status;

    universe->mutex = (struct mutex){0};
    universe->next_handle = 1;

    *out = universe;
    return status;
}
