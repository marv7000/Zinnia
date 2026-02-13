#include <zinnia/channel.h>
#include <zinnia/handle.h>
#include <zinnia/status.h>
#include <zinnia/system.h>

int main() {
    zn_log("Hello, posixd world!\n");

    zn_status_t e;

    // Open a connection to the init server.
    zn_handle_t* handles;
    void* data;
    if ((e = zn_channel_open(ZN_HANDLE_INVALID, 32, 4096, &handles, &data)))
        return e;

    while (1) {}
}
