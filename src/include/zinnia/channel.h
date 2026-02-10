#ifndef ZINNIA_CHANNEL_H
#define ZINNIA_CHANNEL_H

#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <stddef.h>

// Handle which always points to a channel connected to the init server.
#define ZN_INIT_CHANNEL ((zn_handle_t)(-1))

enum zn_channel_flags {
    // Allow sending messages even if one endpoint is not connected.
    ZN_CHANNEL_NONBLOCK = 1 << 0,
};

// Creates a new channel.
zn_status_t zn_channel_create(enum zn_channel_flags flags, zn_handle_t* endpoint0, zn_handle_t* endpoint1);

// Maps the message buffer in the address space and returns its base address.
// There may only be one message buffer per channel and process.
zn_status_t zn_channel_open(
    zn_handle_t channel,
    size_t num_handles,
    size_t num_bytes,
    zn_handle_t** out_handle_buf,
    void** out_data_buf
);

// Waits for a new message to appear in the channel buffer.
zn_status_t zn_channel_read(zn_handle_t channel);

// Writes a message to the
zn_status_t zn_channel_write(zn_handle_t channel);

#endif
