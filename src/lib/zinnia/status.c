#include <zinnia/status.h>

const char* zn_status_to_string(zn_status_t err) {
    switch (err) {
    case ZN_OK:
        return "No error (OK)";
    case ZN_ERR_INTERNAL:
        return "An internal error occured (INTERNAL)";
    case ZN_ERR_BAD_SYSCALL:
        return "Syscall number is not a recognized syscall (BAD_SYSCALL)";
    case ZN_ERR_UNSUPPORTED:
        return "This operation is not supported (UNSUPPORTED)";
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
