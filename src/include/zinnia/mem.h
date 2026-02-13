#ifndef ZINNIA_MEM_H
#define ZINNIA_MEM_H

#ifdef __cplusplus
extern "C" {
#endif

// Virtual memory flags.
enum zn_vm_flags {
    ZN_VM_MAP_READ = 1 << 0,
    ZN_VM_MAP_WRITE = 1 << 1,
    ZN_VM_MAP_EXEC = 1 << 2,
    ZN_VM_MAP_SHARED = 1 << 3,
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

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <stddef.h>

static inline zn_status_t zn_vas_create() {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_vas_map(zn_handle_t space, void* addr, size_t len, enum zn_vm_flags flags) {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_vas_protect(zn_handle_t space, void* addr, size_t len, enum zn_vm_flags flags) {
    return ZN_ERR_UNSUPPORTED;
}

static inline zn_status_t zn_vas_unmap(zn_handle_t space, void* addr, size_t len) {
    return ZN_ERR_UNSUPPORTED;
}

// Creates a new virtual memory object.
static inline zn_status_t zn_vmo_create(size_t length, zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
