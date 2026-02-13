#ifndef ZINNIA_THREAD_H
#define ZINNIA_THREAD_H

#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#ifdef __cplusplus
extern "C" {
#endif

enum zn_thread_flags {
    ZN_THREAD_NONE = 0,
};

#ifndef __KERNEL__

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <stdint.h>
#include <string.h>

// Creates a new thread in the given universe.
static inline zn_status_t zn_thread_create(zn_handle_t universe, const char* name, enum zn_thread_flags flags) {
    return zn_syscall4(
        (zn_arg_t)universe,
        (zn_arg_t)name,
        (zn_arg_t)strlen(name),
        (zn_arg_t)flags,
        ZN_SYSCALL_THREAD_CREATE
    );
}

// Starts executing a thread.
static inline zn_status_t zn_thread_start(zn_handle_t thread, void* ip, void* sp, uintptr_t arg) {
    return ZN_ERR_UNSUPPORTED;
}

// Starts executing a thread.
static inline void zn_thread_exit(void) {
    zn_syscall0(ZN_SYSCALL_THREAD_EXIT);
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
