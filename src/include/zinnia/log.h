#ifndef ZINNIA_LOG_H
#define ZINNIA_LOG_H

#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__

static inline void zn_log(const char* message) {
    zn_syscall2((zn_arg_t)message, (zn_arg_t)strlen(message), ZN_SYSCALL_LOG);
}

// Panics and returns an error status to the parent process.
static inline void zn_panic(zn_status_t status) {
    zn_syscall1((zn_arg_t)status, ZN_SYSCALL_PANIC);
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
