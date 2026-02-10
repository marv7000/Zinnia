#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <kernel/percpu.h>
#include <kernel/syscalls.h>

zn_status_t zn_handle_clone(zn_handle_t handle, zn_rights_t cloned_rights, zn_handle_t* cloned) {
    struct task* current = percpu_get()->sched.current;
    current->process;
    return ZN_ERR_UNSUPPORTED;
}

zn_status_t zn_handle_drop(zn_handle_t handle) {
    struct task* current = percpu_get()->sched.current;

    return ZN_ERR_UNSUPPORTED;
}

zn_status_t zn_handle_validate(zn_handle_t handle) {
    struct task* current = percpu_get()->sched.current;

    return ZN_ERR_UNSUPPORTED;
}
