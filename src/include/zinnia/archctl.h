#ifndef ZINNIA_ARCHCTL_H
#define ZINNIA_ARCHCTL_H

#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    // Does nothing.
    ZN_ARCHCTL_NONE = 0,
#ifdef __x86_64__
    // On x86_64, sets the FSBASE register to the value.
    ZN_ARCHCTL_SET_FSBASE = 1,
#endif
} zn_archctl_t;

#ifndef __KERNEL__

// Performs an architecture-dependent operation identified by `op`.
static inline zn_status_t zn_archctl(zn_archctl_t op, size_t value) {
    return zn_syscall2((zn_arg_t)op, (zn_arg_t)value, ZN_SYSCALL_ARCHCTL);
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
