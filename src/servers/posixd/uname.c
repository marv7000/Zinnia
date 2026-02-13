#include <config.h>
#include <uapi/uname.h>

static struct utsname uname_buf = {
    .sysname = "Zinnia",
    .release = ZINNIA_VERSION,
    .version = "default",
    .domainname = "(none)",
    .nodename = "localhost",
    .machine = ZINNIA_ARCH,
};
