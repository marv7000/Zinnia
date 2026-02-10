#include <zinnia/handle.h>
#include <zinnia/syscall_numbers.h>
#include "syscall_stubs.h"

zn_status_t zn_handle_validate(zn_handle_t handle) {
    return syscall1(ZN_SYSCALL_HANDLE_VALIDATE, (arg_t)handle);
}

zn_status_t zn_handle_drop(zn_handle_t handle) {
    return syscall1(ZN_SYSCALL_HANDLE_DROP, (arg_t)handle);
}

zn_status_t zn_handle_clone(zn_handle_t object, zn_rights_t cloned_rights, zn_handle_t* cloned) {
    return syscall3(ZN_SYSCALL_HANDLE_CLONE, (arg_t)object, (arg_t)cloned_rights, (arg_t)cloned);
}
