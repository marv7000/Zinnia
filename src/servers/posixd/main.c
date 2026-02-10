#include <zinnia/channel.h>
#include <zinnia/handle.h>
#include <zinnia/log.h>
#include <zinnia/status.h>

int main() {
    zn_log("Hello, posixd world!\n");

    zn_status_t e;

    // Open a connection to the init server.
    zn_handle_t* handles;
    void* data;
    if ((e = zn_channel_open(ZN_INIT_CHANNEL, 32, 4096, &handles, &data)))
        return e;

    while (1) {}
}
