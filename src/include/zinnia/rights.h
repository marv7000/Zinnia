#ifndef ZINNIA_RIGHTS_H
#define ZINNIA_RIGHTS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    // Can be read from.
    ZN_RIGHT_READ = 1u << 0,
    // Can be written to.
    ZN_RIGHT_WRITE = 1u << 1,
    // Can be executed.
    ZN_RIGHT_EXECUTE = 1u << 2,
    // Can be mapped in an address space.
    ZN_RIGHT_MAP = 1u << 3,
    // Can be moved to another process.
    ZN_RIGHT_MOVE = 1u << 4,
    // Can be cloned.
    ZN_RIGHT_CLONE = 1u << 5,
    // Can be deleted.
    ZN_RIGHT_DELETE = 1u << 6,

    // When cloning, use the same rights as the original.
    ZN_RIGHTS_IDENTICAL = 1u << 31,
    ZN_RIGHTS_COMMON = (ZN_RIGHT_MOVE | ZN_RIGHT_CLONE),
    ZN_RIGHTS_RW = (ZN_RIGHT_READ | ZN_RIGHT_WRITE),
} zn_rights_t;

#ifdef __cplusplus
}
#endif

#endif
