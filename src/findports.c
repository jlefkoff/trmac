//Copyright Jonah Lefkoff, K0RG, 2025.
//Copyright Larry Tyree, N6TR, 2011,2012,2013,2014,2015.
//
//This file is part of TR log for mac.
//
//TR log for mac is free software: you can redistribute it and/or
//modify it under the terms of the GNU General Public License as
//published by the Free Software Foundation, either version 2 of the
//License, or (at your option) any later version.
//
//TR log for mac is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General
//    Public License along with TR log for mac.  If not, see
//<http://www.gnu.org/licenses/>.

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
