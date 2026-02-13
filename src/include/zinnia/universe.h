#ifndef ZINNIA_UNIVERSE_H
#define ZINNIA_UNIVERSE_H

#include <zinnia/handle.h>
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__
#include <zinnia/status.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

// Returns a handle to the calling thread's universe.
static inline zn_handle_t zn_uni_self(zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

// Creates a new universe.
static inline zn_status_t zn_uni_create(zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
