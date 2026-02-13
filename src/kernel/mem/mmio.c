#include <kernel/mem.h>

void* mem_mmio_new(phys_t addr, size_t length) {
    void* ptr = mem_vm_alloc(length);
    for (size_t i = 0; i < length; i += mem_page_size()) {

        if (mem_pt_map(&mem_pt_kernel, (virt_t)ptr + i, addr + i, PTE_READ | PTE_WRITE, CACHE_MMIO)) {
            mem_vm_free(ptr, length);
            return nullptr;
        }
    }

    return ptr;
}

void mem_mmio_free(void* ptr, size_t length) {
    // TODO
}
