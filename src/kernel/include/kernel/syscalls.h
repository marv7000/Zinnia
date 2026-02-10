#pragma once

#include <zinnia/status.h>
#include <kernel/compiler.h>
#include <kernel/types.h>
#include <stddef.h>
#include <stdint.h>

zn_status_t syscall_dispatch(reg_t num, reg_t a0, reg_t a1, reg_t a2, reg_t a3, reg_t a4, reg_t a5);

[[noreturn]]
void syscall_panic(zn_status_t err);

zn_status_t syscall_log(__user const char* msg, size_t len);

zn_status_t syscall_archctl(uint32_t op, size_t value);
