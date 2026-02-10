#ifndef ZINNIA_LOG_H
#define ZINNIA_LOG_H

#include <zinnia/status.h>

// Panics and returns an error status to the parent process.
void zn_panic(zn_status_t status);

void zn_log(const char* message);

#endif
