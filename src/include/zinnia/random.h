#ifndef ZINNIA_RANDOM_H
#define ZINNIA_RANDOM_H

#ifdef __cplusplus
extern "C" {
#endif

enum {
    ZN_RANDOM_MAX_ENTROPY = 0x1000
};

#ifndef __KERNEL__

#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

// Stores random bytes in a buffer.
static inline zn_status_t zn_random_get(void* addr, size_t len) {
    return zn_syscall2((zn_arg_t)addr, (zn_arg_t)len, ZN_SYSCALL_RANDOM_GET);
}

// Adds entropy to the RNG.
static inline zn_status_t zn_random_entropy(const void* addr, size_t len) {
    return zn_syscall2((zn_arg_t)addr, (zn_arg_t)len, ZN_SYSCALL_RANDOM_ENTROPY);
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
