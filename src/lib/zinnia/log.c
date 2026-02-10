#include <zinnia/log.h>
#include <zinnia/status.h>
#include <zinnia/syscall_numbers.h>
#include <string.h>
#include "syscall_stubs.h"

void zn_log(const char* message) {
    syscall2(ZN_SYSCALL_LOG, (arg_t)message, (arg_t)strlen(message));
}
