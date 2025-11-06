#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * Simple helper to open a pty master on platforms that provide posix_openpt.
 * Returns the file descriptor or -1 on failure.
 */
int getpt(void) {
    int fd = posix_openpt(O_RDWR | O_NOCTTY);
    if (fd < 0) return -1;
    return fd;
}
