#include <zinnia/channel.h>
#include <zinnia/syscall_numbers.h>
#include "syscall_stubs.h"

zn_status_t zn_channel_create(enum zn_channel_flags flags, zn_handle_t* endpoint0, zn_handle_t* endpoint1) {
    return syscall3(ZN_SYSCALL_CHANNEL_CREATE, (arg_t)flags, (arg_t)endpoint0, (arg_t)endpoint1);
}

zn_status_t zn_channel_open(
    zn_handle_t channel,
    size_t num_handles,
    size_t num_bytes,
    zn_handle_t** out_handle_buf,
    void** out_data_buf
) {
    return syscall5(
        ZN_SYSCALL_CHANNEL_OPEN,
        (arg_t)channel,
        (arg_t)num_handles,
        (arg_t)num_bytes,
        (arg_t)out_handle_buf,
        (arg_t)out_data_buf
    );
}

zn_status_t zn_channel_write(zn_handle_t channel) {
    return syscall1(ZN_SYSCALL_CHANNEL_WRITE, (arg_t)channel);
}
