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

#ifndef __KERNEL__

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

// Creates a new virtual memory object.
static inline zn_status_t zn_vmo_create(size_t length, zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

// Creates a new virtual memory object which points to a contiguous phyiscal memory region.
static inline zn_status_t zn_vmo_create_phys(uintptr_t phys_addr, size_t length, zn_handle_t* out) {
    return ZN_ERR_UNSUPPORTED;
}

// Creates a new virtual address space.
static inline zn_status_t zn_vas_create(zn_handle_t* out) {
    return zn_syscall1((zn_arg_t)out, ZN_SYSCALL_VAS_CREATE);
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

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
