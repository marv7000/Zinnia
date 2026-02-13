#ifndef ZINNIA_CHANNEL_H
#define ZINNIA_CHANNEL_H

#ifdef __cplusplus
extern "C" {
#endif

enum zn_channel_flags {
    // Allow sending messages even if one endpoint is not connected.
    ZN_CHANNEL_NONBLOCK = 1 << 0,
};

#ifndef __KERNEL__

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <zinnia/syscall_stubs.h>
#include <stddef.h>

// Creates a new channel.
static inline zn_status_t zn_channel_create(
    enum zn_channel_flags flags,
    zn_handle_t* endpoint0,
    zn_handle_t* endpoint1
) {
    return zn_syscall3((zn_arg_t)flags, (zn_arg_t)endpoint0, (zn_arg_t)endpoint1, ZN_SYSCALL_CHANNEL_CREATE);
}

// Notifies the peer that there is new data available.
// The kernel only copies the first `num_handles` handles and `num_bytes` bytes.
static inline zn_status_t zn_channel_write(
    zn_handle_t channel,
    zn_handle_t* handles,
    void* bytes,
    size_t num_handles,
    size_t num_bytes
) {
    return zn_syscall5(
        (zn_arg_t)channel,
        (zn_arg_t)handles,
        (zn_arg_t)bytes,
        (zn_arg_t)num_handles,
        (zn_arg_t)num_bytes,
        ZN_SYSCALL_CHANNEL_WRITE
    );
}

// Waits for a new message to appear in the channel.
static inline zn_status_t zn_channel_read(
    zn_handle_t channel,
    zn_handle_t* handles,
    void* bytes,
    size_t num_handles,
    size_t num_bytes,
    size_t* read_handles,
    size_t* read_bytes
) {
    return zn_syscall7(
        (zn_arg_t)channel,
        (zn_arg_t)handles,
        (zn_arg_t)bytes,
        (zn_arg_t)num_handles,
        (zn_arg_t)num_bytes,
        (zn_arg_t)read_handles,
        (zn_arg_t)read_bytes,
        ZN_SYSCALL_CHANNEL_READ
    );
}

#endif // !__KERNEL__

#ifdef __cplusplus
}
#endif

#endif
