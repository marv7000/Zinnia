#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <kernel/compiler.h>
#include <kernel/syscalls.h>
#include <kernel/types.h>

zn_status_t syscall_dispatch(reg_t num, reg_t a0, reg_t a1, reg_t a2, reg_t a3, reg_t a4, reg_t a5) {
    switch (num) {
    case ZN_SYSCALL_PANIC:
        syscall_panic((zn_status_t)a0);
    case ZN_SYSCALL_LOG:
        return syscall_log((__user const char*)a0, a1);
    case ZN_SYSCALL_ARCHCTL:
        return syscall_archctl(a0, a1);
    }

    return ZN_ERR_BAD_SYSCALL;
}
