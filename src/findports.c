//
// Portable findports.c (macOS & Linux)
// Copyright Larry Tyree, N6TR, 2011–2015.
// Ported for macOS by ChatGPT, 2025.
//
// This file is part of TR log for linux/mac.
//
// Licensed under the GPL v2 or later.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <glob.h>

#define BUFSIZE 1024
#define DEVSIZE 256

static void catstr(char *dest, const char *src, int ndest) {
    if (strlen(dest) + strlen(src) < (size_t)(ndest - 1)) {
        strcat(dest, src);
    } else {
        strncat(dest, src, ndest - strlen(dest) - 1);
        dest[ndest - 1] = '\0';
    }
}

// On macOS, serial ports usually appear as /dev/tty.* or /dev/cu.*
int findserial(char **buf, int bufsize, int n) {
    int count = 0;
    glob_t globbuf;
    memset(&globbuf, 0, sizeof(globbuf));

    const char *patterns[] = { "/dev/tty.*", "/dev/cu.*" };

    for (size_t i = 0; i < sizeof(patterns) / sizeof(patterns[0]); ++i) {
        if (glob(patterns[i],
                 (i == 0 ? 0 : GLOB_APPEND) | GLOB_NOSORT,
                 NULL,
                 &globbuf) != 0) {
            continue;
        }
    }

    for (size_t i = 0; i < globbuf.gl_pathc && count < n; ++i) {
        const char *dev = globbuf.gl_pathv[i];
        if (strlen(dev) < (size_t)(bufsize - 1)) {
            strcpy(buf[count], dev);
        } else {
            strncpy(buf[count], dev, bufsize - 1);
            buf[count][bufsize - 1] = '\0';
        }
        count++;
    }

    globfree(&globbuf);
    return count;
}

int findparallel(char **buf, int bufsize, int n) {
    // macOS doesn’t have parallel ports (IEEE1284)
    (void)buf;
    (void)bufsize;
    (void)n;
    return 0;
}

/*
#define PNUM 10
int main(void) {
    char **buf;
    int i, n;
    buf = (char**) malloc(PNUM * sizeof(char*));
    for (i = 0; i < PNUM; i++) {
        buf[i] = (char*) malloc(80 * sizeof(char));
    }

    printf("Serial ports:\n");
    n = findserial(buf, 80, PNUM);
    for (i = 0; i < n; i++)
        printf("  %s\n", buf[i]);

    printf("\nParallel ports:\n");
    n = findparallel(buf, 80, PNUM);
    for (i = 0; i < n; i++)
        printf("  %s\n", buf[i]);

    for (i = 0; i < PNUM; i++)
        free(buf[i]);
    free(buf);
    return 0;
}
*/

