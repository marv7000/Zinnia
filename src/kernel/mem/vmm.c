#include <kernel/common.h>
#include <kernel/mem.h>
#include <stdatomic.h>
#include <stddef.h>

// TODO: Replace with actual allocator.

static size_t mapping_offset = 0;

void* mem_vm_alloc(size_t length) {
    virt_t base = mem_mapping_addr();
    size_t offset = atomic_fetch_add(&mapping_offset, ALIGN_UP(length, mem_page_size()));

    return (void*)(base + offset);
}

void mem_vm_free(void* ptr, size_t length) {
    // TODO
}
