#ifndef ZINNIA_THREAD_H
#define ZINNIA_THREAD_H

#include <zinnia/handle.h>
#include <zinnia/status.h>

enum zn_thread_flags {
    ZN_THREAD_NONE,
};

// Creates a new thread.
zn_status_t zn_thread_create(const char* name, zn_handle_t address_space, enum zn_thread_flags flags);

#endif
