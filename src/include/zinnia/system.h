#ifndef ZINNIA_SYSTEM_H
#define ZINNIA_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __KERNEL__
#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <string.h>

static inline void zn_log(const char* message) {
    zn_syscall2((zn_arg_t)message, (zn_arg_t)strlen(message), ZN_SYSCALL_LOG);
}

// Returns the page size of the system.
static inline size_t zn_page_size() {
    size_t size = 0;
    zn_syscall1((zn_arg_t)&size, ZN_SYSCALL_PAGE_SIZE);
    return size;
}

static inline zn_status_t zn_powerctl() {
    return ZN_ERR_UNSUPPORTED;
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
