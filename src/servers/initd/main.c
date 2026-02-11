#include <zinnia/channel.h>
#include <zinnia/handle.h>
#include <zinnia/log.h>
#include <zinnia/status.h>
#include <libzinnia/status.h>

int main() {
    zn_log("Hello, init world!\n");

    // Create the root channel so other processes can find each other.
    zn_status_t e;
    zn_handle_t end0, end1;
    zn_log("init: Creating root channel\n");
    if ((e = zn_channel_create(0, &end0, &end1))) {
        zn_log(zn_status_to_string(e));
        return e;
    }

    return 0;
}
