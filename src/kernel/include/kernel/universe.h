#pragma once

#include <zinnia/handle.h>
#include <kernel/channel.h>
#include <kernel/mem.h>
#include <kernel/mutex.h>
#include <kernel/spin.h>
#include <stddef.h>

enum universe_desc_type {
    UNIVERSE_DESC_UNIVERSE,
    UNIVERSE_DESC_TASK,
    UNIVERSE_DESC_VAS,
};

struct universe_desc {
    enum universe_desc_type type;
};

// Translates between handles and objects.
struct universe {
    size_t next_handle;
    struct mutex mutex;
};

struct universe_uni_desc {
    enum universe_desc_type type;
    struct universe* universe;
};

struct universe_channel_desc {
    struct universe_desc desc;
    struct channel* channel;
};

struct universe_vas_desc {
    struct universe_desc desc;
    struct address_space* space;
};

// Creates a new universe with no contents.
zn_status_t universe_new(struct universe** out);

// Adds a descriptor to this universe.
zn_handle_t universe_add_desc(struct universe* universe, struct universe_desc* desc);

// Deletes a descriptor from this universe.
void universe_del_desc(struct universe* universe, zn_handle_t handle);
