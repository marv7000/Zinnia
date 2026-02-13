#ifndef ZINNIA_STATUS_H
#define ZINNIA_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

// Status values that may be returned by syscalls or other calls.
// A status value of 0 means no error occured.
// A negative value indicates a common error, usually from the kernel.
typedef enum {
    ZN_OK = 0,
    // An internal error occured.
    ZN_ERR_INTERNAL = -1,
    // Syscall number is not a recognized syscall.
    ZN_ERR_BAD_SYSCALL = -2,
    // This operation is not supported or implemented yet.
    ZN_ERR_UNSUPPORTED = -3,
    // System does not have enough free memory for this operation.
    ZN_ERR_NO_MEMORY = -4,
    // Process can not own any more handles.
    ZN_ERR_NO_HANDLES = -5,
    // One or more of the provided arguments is not valid.
    ZN_ERR_BAD_ARG = -6,
    // Argument is outside of the range for valid values.
    ZN_ERR_BAD_RANGE = -7,
    // Object handle does not name a valid object or correct type.
    ZN_ERR_BAD_OBJECT = -8,
    // Object has insufficient permissions for this operation.
    ZN_ERR_BAD_PERMS = -9,
    // Buffer is not large enough or doesn't point to a valid memory region.
    ZN_ERR_BAD_BUFFER = -10,
} zn_status_t;

#ifndef __KERNEL__

static inline const char* zn_status_to_string(zn_status_t err) {
    switch (err) {
    case ZN_OK:
        return "No error (OK)";
    case ZN_ERR_INTERNAL:
        return "An internal error occured (INTERNAL)";
    case ZN_ERR_BAD_SYSCALL:
        return "Syscall number is not a recognized syscall (BAD_SYSCALL)";
    case ZN_ERR_UNSUPPORTED:
        return "This operation is not supported or implemented yet (UNSUPPORTED)";
    case ZN_ERR_NO_MEMORY:
        return "System does not have enough free memory for this operation (NO_MEMORY)";
    case ZN_ERR_NO_HANDLES:
        return "Process can not own any more handles (NO_HANDLES)";
    case ZN_ERR_BAD_ARG:
        return "One or more of the provided arguments is not valid (BAD_ARG)";
    case ZN_ERR_BAD_RANGE:
        return "Argument is outside of the range for valid values (BAD_RANGE)";
    case ZN_ERR_BAD_OBJECT:
        return "Object handle does not name a valid object (BAD_OBJECT)";
    case ZN_ERR_BAD_PERMS:
        return "Object has insufficient permissions for this operation (BAD_PERMS)";
    case ZN_ERR_BAD_BUFFER:
        return "Buffer is not large enough or doesn't point to a valid memory region (BAD_BUFFER)";
    }

    return "Unknown error code";
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
