#ifndef ZINNIA_ARCHCTL_H
#define ZINNIA_ARCHCTL_H

#include <zinnia/status.h>
#include <stddef.h>

typedef enum {
    // Does nothing.
    ZN_ARCHCTL_NONE = 0,
#ifdef __x86_64__
    // On x86_64, sets the FSBASE register to the value.
    ZN_ARCHCTL_SET_FSBASE = 1,
#endif
} zn_archctl_t;

// Performs an architecture-dependent operation identified by `op`.
zn_status_t zn_archctl(zn_archctl_t op, size_t value);

#endif
