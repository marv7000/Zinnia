#ifndef ZINNIA_UNIVERSE_H
#define ZINNIA_UNIVERSE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

// Creates a new universe.
static inline zn_status_t zn_uni_create(zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_uni_move(zn_handle_t handle, zn_handle_t target_universe) {
    return ZN_ERR_UNSUPPORTED;
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
