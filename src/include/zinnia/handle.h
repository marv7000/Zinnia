#ifndef ZINNIA_HANDLE_H
#define ZINNIA_HANDLE_H

#include <zinnia/rights.h>
#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// A generic object handle.
typedef size_t zn_handle_t;

#define ZN_HANDLE_INVALID ((zn_handle_t)(0))

#ifndef __KERNEL__

// Checks an object handle for validity.
static inline zn_status_t zn_handle_validate(zn_handle_t handle) {
    return zn_syscall1((zn_arg_t)handle, ZN_SYSCALL_HANDLE_VALIDATE);
}

// Drops a an object handle.
// All further references using this handle are invalid. The numerical value
// may become valid again, but it is an error to keep using it.
// The underlying object gets freed only once no other handle references it.
static inline zn_status_t zn_handle_drop(zn_handle_t handle) {
    return zn_syscall1((zn_arg_t)handle, ZN_SYSCALL_HANDLE_DROP);
}

// Creates a new handle pointing to the same object as pointed to
// by the original handle. The new handle may obtain new rights.
static inline zn_status_t zn_handle_clone(zn_handle_t handle, zn_rights_t cloned_rights, zn_handle_t* cloned) {
    return zn_syscall3((zn_arg_t)handle, (zn_arg_t)cloned_rights, (zn_arg_t)cloned, ZN_SYSCALL_HANDLE_CLONE);
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
