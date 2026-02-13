#pragma once

#include <x86_64/apic.h>
#include <x86_64/gdt.h>

static inline struct percpu* arch_percpu_get() {
    struct percpu* result;
    asm volatile("mov %0, gs:0" : "=r"(result)::"memory");
    return result;
}

struct arch_percpu {
    struct gdt gdt;
    struct tss tss;
    struct local_apic lapic;
};
