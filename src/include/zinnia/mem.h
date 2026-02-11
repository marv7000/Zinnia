#ifndef ZINNIA_MEM_H
#define ZINNIA_MEM_H

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Virtual memory flags.
enum zn_vm_flags {
    ZN_VM_READ = 1 << 0,
    ZN_VM_WRITE = 1 << 1,
    ZN_VM_EXEC = 1 << 2,
    ZN_VM_SHARED = 1 << 3,
};

enum zn_cache_type {
    // Generic memory
    ZN_CACHE_NORMAL,
    // Write combining
    ZN_CACHE_WC,
    // Memory-mapped IO
    ZN_CACHE_MMIO,
};

#ifndef __KERNEL__

// Allocates memory
static inline zn_status_t zn_mem_alloc(size_t length, zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_mem_map(zn_handle_t mem, void* addr, size_t len, enum zn_vm_flags flags) {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_mem_unmap(zn_handle_t mem, void* addr, size_t len, enum zn_vm_flags flags) {
    return ZN_ERR_UNSUPPORTED;
}

// Stores random bytes in a buffer.
static inline zn_status_t zn_mem_randset(void* addr, size_t len) {
    return ZN_ERR_UNSUPPORTED;
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
